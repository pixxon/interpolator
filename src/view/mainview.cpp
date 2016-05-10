#include "mainview.h"


#include <QLayout>
#include <QLayoutItem>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QDoubleValidator>
#include <QException>
#include <limits>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainView::MainView(QWidget *parent) :
    QWidget(parent)
{
}

MainView::~MainView()
{
}

void MainView::showEvent(QShowEvent*)
{
    _help = new HelpView(this);

    //_top_page_1
    _topPage1 = new QWidget(this);
    _funcInput = new QLineEdit(this);

    QVBoxLayout* topPage1Layout = new QVBoxLayout(this);
    topPage1Layout->addWidget(new QLabel("Függvény képlete", this), 0, Qt::AlignBottom);
    topPage1Layout->addWidget(_funcInput, 0, Qt::AlignTop);

    _topPage1->setLayout(topPage1Layout);

    //_top_page_2
    _topPage2 = new QWidget(this);

    //_top_pages
    _top = new QTabWidget(this);
    _top->addTab(_topPage1, "Függvény");
    _top->addTab(_topPage2, "Értékek");

    //_bottom_page_1
    _bottomPage1 = new QWidget(this);
    _partMinX = new QDoubleSpinBox(this);
    _partMinX->setFixedSize(110, 25);
    _partMinX->setMinimum(-std::numeric_limits<double>::max());
    _partMinX->setValue(-1);
    QObject::connect(_partMinX, SIGNAL(valueChanged(double)), this, SLOT(partChangedX()));

    _partMaxX = new QDoubleSpinBox(this);
    _partMaxX->setFixedSize(110, 25);
    _partMaxX->setMaximum(+std::numeric_limits<double>::max());
    _partMaxX->setValue(1);
    QObject::connect(_partMaxX, SIGNAL(valueChanged(double)), this, SLOT(partChangedX()));

    _partCountX = new QSpinBox(this);
    _partCountX->setFixedSize(110, 25);
    _partCountX->setMinimum(2);
    _partCountX->setMaximum(10);
    QObject::connect(_partCountX, SIGNAL(valueChanged(int)), this, SLOT(partChangedX()));

    _partTypeX = new QComboBox(this);
    _partTypeX->setFixedSize(110, 25);
    _partTypeX->addItems(QStringList({"Egyenletes", "Csebisev"}));
    QObject::connect(_partTypeX, SIGNAL(currentIndexChanged(int)), this, SLOT(partChangedX()));

    _partMinY = new QDoubleSpinBox(this);
    _partMinY->setFixedSize(110, 25);
    _partMinY->setMinimum(-std::numeric_limits<double>::max());
    _partMinY->setValue(-1);
    QObject::connect(_partMinY, SIGNAL(valueChanged(double)), this, SLOT(partChangedY()));

    _partMaxY = new QDoubleSpinBox(this);
    _partMaxY->setFixedSize(110, 25);
    _partMaxY->setMaximum(+std::numeric_limits<double>::max());
    _partMaxY->setValue(1);
    QObject::connect(_partMaxY, SIGNAL(valueChanged(double)), this, SLOT(partChangedY()));

    _partCountY = new QSpinBox(this);
    _partCountY->setFixedSize(110, 25);
    _partCountY->setMinimum(2);
    _partCountY->setMaximum(10);
    QObject::connect(_partCountY, SIGNAL(valueChanged(int)), this, SLOT(partChangedY()));

    _partTypeY = new QComboBox(this);
    _partTypeY->setFixedSize(110, 25);
    _partTypeY->addItems(QStringList({"Egyenletes", "Csebisev"}));
    QObject::connect(_partTypeY, SIGNAL(currentIndexChanged(int)), this, SLOT(partChangedY()));

    QGridLayout* bottomPage1Layout = new QGridLayout();


    bottomPage1Layout->addWidget(new QLabel("X tengely",this), 0, 0, 1, 4, Qt::AlignCenter);
    bottomPage1Layout->addWidget(new QLabel("Alsó határ", this), 1, 0, 1, 1);
    bottomPage1Layout->addWidget(_partMinX, 2, 0, 1, 1);
    bottomPage1Layout->addWidget(new QLabel("Felső határ", this), 1, 1, 1, 1);
    bottomPage1Layout->addWidget(_partMaxX, 2, 1, 1, 1);
    bottomPage1Layout->addWidget(new QLabel("Pontok száma", this), 1, 2, 1, 1);
    bottomPage1Layout->addWidget(_partCountX, 2, 2, 1, 1);
    bottomPage1Layout->addWidget(new QLabel("Felosztás típusa", this), 1, 3, 1, 1);
    bottomPage1Layout->addWidget(_partTypeX, 2, 3, 1, 1);

    bottomPage1Layout->addWidget(new QLabel("Y tengely",this), 3, 0, 1, 4, Qt::AlignCenter);
    bottomPage1Layout->addWidget(new QLabel("Alsó határ", this), 4, 0, 1, 1);
    bottomPage1Layout->addWidget(_partMinY, 5, 0, 1, 1);
    bottomPage1Layout->addWidget(new QLabel("Felső határ", this), 4, 1, 1, 1);
    bottomPage1Layout->addWidget(_partMaxY, 5, 1, 1, 1);
    bottomPage1Layout->addWidget(new QLabel("Pontok száma", this), 4, 2, 1, 1);
    bottomPage1Layout->addWidget(_partCountY, 5, 2, 1, 1);
    bottomPage1Layout->addWidget(new QLabel("Felosztás típusa", this), 4, 3, 1, 1);
    bottomPage1Layout->addWidget(_partTypeY, 5, 3, 1, 1);

    _bottomPage1->setLayout(bottomPage1Layout);

    //_bottom_page_2
    _bottomPage2 = new QWidget(this);

    QGridLayout* _bottom2Layout = new QGridLayout();

    _part2CountX = new QSpinBox(this);
    _part2CountX->setFixedSize(110, 25);
    _part2CountX->setMinimum(2);
    _part2CountX->setMaximum(10);
    QObject::connect(_part2CountX, SIGNAL(valueChanged(int)), this, SLOT(countChanged()));

    _part2CountY = new QSpinBox(this);
    _part2CountY->setFixedSize(110, 25);
    _part2CountY->setMinimum(2);
    _part2CountY->setMaximum(10);
    QObject::connect(_part2CountY, SIGNAL(valueChanged(int)), this, SLOT(countChanged()));

    _bottom2Layout->addWidget(new QLabel("X tengelyen pontok száma:", this), 0, 0, 1, 4, Qt::AlignLeft);
    _bottom2Layout->addWidget(_part2CountX, 0, 4, 1, 6, Qt::AlignLeft);

    _part2BaseX.resize(_part2CountX->value());
    for (int i = 0; i < _part2BaseX.size(); i++)
    {
        _part2BaseX[i] = new QLineEdit();
        _part2BaseX[i] ->setFixedHeight(25);
        _part2BaseX[i] ->setFixedWidth(50);
        _part2BaseX[i] ->setValidator(new QDoubleValidator());
        QObject::connect(_part2BaseX[i], SIGNAL(editingFinished()), this, SLOT(partChangedX()));
       _bottom2Layout->addWidget(_part2BaseX[i], 1, i, 1, 1);
    }
    for (int i = _part2BaseX.size(); i < 10; i++)
    {
        QLabel* tmp = new QLabel(this);
        tmp->setFixedHeight(25);
        tmp->setFixedWidth(50);
       _bottom2Layout->addWidget(tmp, 1, i, 1, 1);
    }

    _bottom2Layout->addWidget(new QLabel("Y tengelyen pontok száma:", this), 2, 0, 1, 4, Qt::AlignLeft);
    _bottom2Layout->addWidget(_part2CountY, 2, 4, 1, 6, Qt::AlignLeft);

    _part2BaseY.resize(_part2CountY->value());
    for (int i = 0; i < _part2BaseY.size(); i++)
    {
        _part2BaseY[i] = new QLineEdit();
        _part2BaseY[i] ->setFixedHeight(25);
        _part2BaseY[i] ->setFixedWidth(50);
        _part2BaseY[i] ->setValidator(new QDoubleValidator());
        QObject::connect(_part2BaseY[i], SIGNAL(editingFinished()), this, SLOT(partChangedY()));
       _bottom2Layout->addWidget(_part2BaseY[i], 3, i, 1, 1);
    }
    for (int i = _part2BaseY.size(); i < 10; i++)
    {
        QLabel* tmp = new QLabel(this);
        tmp->setFixedHeight(25);
        tmp->setFixedWidth(50);
       _bottom2Layout->addWidget(tmp, 3, i, 1, 1);
    }

    _bottomPage2->setLayout(_bottom2Layout);


    //_bottom_pages
    _bottom = new QTabWidget(this);
    _bottom->addTab(_bottomPage1, "Felosztás");
	_bottom->addTab(_bottomPage2, "Alappontok");
    QObject::connect(_bottom, SIGNAL(currentChanged(int)), this, SLOT(partChangedX()));
    QObject::connect(_bottom, SIGNAL(currentChanged(int)), this, SLOT(partChangedY()));

    //_button
    _renderButton = new QPushButton("Kirajzolás", this);
    QObject::connect(_renderButton, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));

    _oneDimension = new QPushButton("Egy dimenzió", this);
    QObject::connect(_oneDimension, SIGNAL(clicked(bool)), this, SLOT(dimensionChanged()));
    _oneDimension->setCheckable(true);

    _showSteps = new QPushButton("Lépések kiírása", this);
    _showSteps->setCheckable(true);

    _helpButton = new QPushButton("Súgó", this);
    QObject::connect(_helpButton, SIGNAL(clicked(bool)), this, SLOT(helpClicked()));

    QPushButton* load = new QPushButton("Betöltés fájlból", this);
    QObject::connect(load, SIGNAL(clicked(bool)), this, SLOT(loadFromFile()));

    QPushButton* save = new QPushButton("Mentés fájlba", this);
    QObject::connect(save, SIGNAL(clicked(bool)), this, SLOT(saveToFile()));

    QVBoxLayout* menuLayout = new QVBoxLayout();
    menuLayout->addWidget(load, Qt::AlignTop);
    menuLayout->addWidget(save, Qt::AlignTop);
    menuLayout->addWidget(_oneDimension, Qt::AlignTop);
    menuLayout->addWidget(_showSteps, Qt::AlignTop);
    menuLayout->addWidget(_helpButton, Qt::AlignTop);
    menuLayout->addStretch();
    menuLayout->addWidget(_renderButton, Qt::AlignTop);

    //_all
    QVBoxLayout* inputLayout = new QVBoxLayout();
    inputLayout->addWidget(_bottom);
    inputLayout->addWidget(_top);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(menuLayout);

    setLayout(mainLayout);

    partSet('x', _partMinX->value(), _partMaxX->value(), _partCountX->value(), _partTypeX->currentText());
    partSet('y', _partMinY->value(), _partMaxY->value(), _partCountY->value(), _partTypeY->currentText());
}

bool MainView::hasEmpty()
{
    if (_top->currentIndex() == 0)
    {
        if (_funcInput->text() == "")
        {
            return true;
        }
    }

    if (_top->currentIndex() == 1)
    {
        for (int i = 0; i < _pointInput.size(); i++)
        {
            for (int j = 0; j < _pointInput[i].size(); j++)
            {
                if (_pointInput[i][j]->text() == "")
                {
                    return true;
                }
            }
        }
    }

    if (_bottom->currentIndex() == 1)
    {
        for (int i = 0; i < _part2BaseX.size(); i++)
        {
            if (_part2BaseX[i]->text() == "")
            {
                return true;
            }
            else
            {
                for(int j = 0; j < i; j++)
                {
                    if (_part2BaseX[i]->text() == _part2BaseX[j]->text())
                    {
                        return true;
                    }
                }
            }
        }

        if (_oneDimension->isChecked())
            return false;

        for (int i = 0; i < _part2BaseY.size(); i++)
        {
            if (_part2BaseY[i]->text() == "")
            {
                return true;
            }
            else
            {
                for(int j = 0; j < i; j++)
                {
                    if (_part2BaseY[i]->text() == _part2BaseY[j]->text())
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void MainView::buttonClick()
{
    if (hasEmpty())
    {
        QMessageBox::warning(this, "Hiba!", "Hiányos adat, vagy azonos alappont!");
        return;
    }

	if (_top->currentIndex() == 0)
    {
        inputSet(_funcInput->text());
	}

	if (_top->currentIndex() == 1)
	{
		QVector<QVector<double>> points;

		points.resize(_pointInput.size());
        for (int i = 0; i < _pointInput.size(); i++)
        {
            points[i].resize(_pointInput[i].size());
            for (int j = 0; j < _pointInput[i].size(); j++)
            {
                points[i][j] = _pointInput[i][j]->text().replace(",",".").toDouble();
			}
		}

		inputSet(points);
	}
}

void MainView::partChangedX()
{
    if (_bottom->currentIndex() == 0)
    {
        partSet('x', _partMinX->value(), _partMaxX->value(), _partCountX->value(), _partTypeX->currentText());
        _partMinX->setMaximum(_partMaxX->value() - 0.01);
        _partMaxX->setMinimum(_partMinX->value() + 0.01);
    }
    else
    {
        QVector<double> baseX;
        for (int i = 0; i < _part2BaseX.size(); i++)
        {
            if (_part2BaseX[i]->text() == "")
            {
                partSet('x', {});
                return;
            }
            else
            {
                for(int j = 0; j < i; j++)
                {
                    if (_part2BaseX[i]->text() == _part2BaseX[j]->text())
                    {
                        partSet('x', {});

                        QMessageBox::warning(this, "Hiba!", "Azonos alappont!");

                        return;
                    }
                }
            }
            baseX.push_back(_part2BaseX[i]->text().replace(",",".").toDouble());
        }
        partSet('x', baseX);
    }
}

void MainView::partChangedY()
{
    if (_oneDimension->isChecked())
    {
        return;
    }

    if (_bottom->currentIndex() == 0)
    {
        partSet('y', _partMinY->value(), _partMaxY->value(), _partCountY->value(), _partTypeY->currentText());
        _partMinY->setMaximum(_partMaxY->value() - 0.01);
        _partMaxY->setMinimum(_partMinY->value() + 0.01);
    }
    else
    {
        QVector<double> baseY;
        for (int i = 0; i < _part2BaseY.size(); i++)
        {
            if (_part2BaseY[i]->text() == "")
            {
                partSet('y', {});
                return;
            }
            else
            {
                for(int j = 0; j < i; j++)
                {
                    if (_part2BaseY[i]->text() == _part2BaseY[j]->text())
                    {
                        partSet('y', {});

                        QMessageBox::warning(this, "Hiba!", "Azonos alappont!");

                        return;
                    }
                }
            }
            baseY.push_back(_part2BaseY[i]->text().replace(",",".").toDouble());
        }
        partSet('y', baseY);
    }
}

void MainView::dimensionChanged()
{
    dimensionChanged(_oneDimension->isChecked());
    if(_oneDimension->isChecked())
    {
        _partMinY->setEnabled(false);
        _partMaxY->setEnabled(false);
        _partCountY->setEnabled(false);
        _partTypeY->setEnabled(false);

        _part2CountY->setEnabled(false);
        for (int i = 0; i < _part2BaseY.size(); i++)
        {
            _part2BaseY[i]->setEnabled(false);
        }

        partSet('y', {0});
    }
    else
    {
        _partMinY->setEnabled(true);
        _partMaxY->setEnabled(true);
        _partCountY->setEnabled(true);
        _partTypeY->setEnabled(true);

        _part2CountY->setEnabled(true);
        for (int i = 0; i < _part2BaseY.size(); i++)
        {
            _part2BaseY[i]->setEnabled(true);
        }

        partChangedY();
    }
}

void MainView::countChanged()
{
    QLayout* layout = _bottomPage2->layout();
    if (layout != 0)
    {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)))
        {
            layout->removeItem(item);
            if (item->widget() != _part2CountX && item->widget() != _part2CountY)
            {
                item->widget()->hide();
                delete item;
            }
        }
        delete layout;
    }

    QGridLayout* _bottom2Layout = new QGridLayout();

    _bottom2Layout->addWidget(new QLabel("X tengelyen pontok száma:", this), 0, 0, 1, 4, Qt::AlignLeft);
    _bottom2Layout->addWidget(_part2CountX, 0, 4, 1, 6, Qt::AlignLeft);

    _part2BaseX.resize(_part2CountX->value());
    for (int i = 0; i < _part2BaseX.size(); i++)
    {
        _part2BaseX[i] = new QLineEdit();
        _part2BaseX[i] ->setFixedHeight(25);
        _part2BaseX[i] ->setFixedWidth(50);
        _part2BaseX[i] ->setValidator(new QDoubleValidator());
        QObject::connect(_part2BaseX[i], SIGNAL(editingFinished()), this, SLOT(partChangedX()));
       _bottom2Layout->addWidget(_part2BaseX[i], 1, i, 1, 1);
    }
    for (int i = _part2BaseX.size(); i < 10; i++)
    {
        QLabel* tmp = new QLabel(this);
        tmp->setFixedHeight(25);
        tmp->setFixedWidth(50);
       _bottom2Layout->addWidget(tmp, 1, i, 1, 1);
    }

    _bottom2Layout->addWidget(new QLabel("Y tengelyen pontok száma:", this), 2, 0, 1, 4, Qt::AlignLeft);
    _bottom2Layout->addWidget(_part2CountY, 2, 4, 1, 6, Qt::AlignLeft);

    _part2BaseY.resize(_part2CountY->value());
    for (int i = 0; i < _part2BaseY.size(); i++)
    {
        _part2BaseY[i] = new QLineEdit();
        _part2BaseY[i] ->setFixedHeight(25);
        _part2BaseY[i] ->setFixedWidth(50);
        _part2BaseY[i] ->setValidator(new QDoubleValidator());

        if (_oneDimension->isChecked())
        {
            _part2BaseY[i]->setEnabled(false);
        }

        QObject::connect(_part2BaseY[i], SIGNAL(editingFinished()), this, SLOT(partChangedY()));
       _bottom2Layout->addWidget(_part2BaseY[i], 3, i, 1, 1);
    }
    for (int i = _part2BaseY.size(); i < 10; i++)
    {
        QLabel* tmp = new QLabel(this);
        tmp->setFixedHeight(25);
        tmp->setFixedWidth(50);
       _bottom2Layout->addWidget(tmp, 3, i, 1, 1);
    }

    _bottomPage2->setLayout(_bottom2Layout);

    partChangedX();
    partChangedY();
}

void MainView::partChanged(QVector<double> partX, QVector<double> partY)
{
    QLayout* layout = _topPage2->layout();
    if (layout != 0)
    {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)))
        {
            layout->removeItem(item);
            item->widget()->hide();
            delete item;
        }
        delete layout;
    }

    _topPage2->setFixedHeight(360);
    _topPage2->setFixedWidth(600);

    QGridLayout* _top_page_2_layout = new QGridLayout();

    for (int i = 0; i < partY.size(); i++)
    {
        QLabel* num = new QLabel(QString::number(partY[i], 'f', 4));
        num->setFixedHeight(25);
        num->setFixedWidth(50);
        num->setAlignment(Qt::AlignCenter);
        _top_page_2_layout->addWidget(num, 1, i + 2, 1, 1);
    }

    for (int i = 0; i < partX.size(); i++)
    {
        QLabel* num = new QLabel(QString::number(partX[i], 'f', 4));
        num->setFixedHeight(25);
        num->setFixedWidth(50);
        num->setAlignment(Qt::AlignCenter);
        _top_page_2_layout->addWidget(num, i + 2, 1, 1, 1);
    }

    _pointInput.resize(partX.size());
    for (int i = 0; i < _pointInput.size(); i++)
    {
        _pointInput[i].resize(partY.size());
        for (int j = 0; j < _pointInput[i].size(); j++)
        {
            _pointInput[i][j] = new QLineEdit();
            _pointInput[i][j]->setFixedHeight(25);
            _pointInput[i][j]->setFixedWidth(50);
            _pointInput[i][j]->setValidator(new QDoubleValidator());
            _top_page_2_layout->addWidget(_pointInput[i][j], i + 2, j + 2, 1, 1);
        }
    }

    _topPage2->setLayout(_top_page_2_layout);
}

void MainView::closeEvent(QCloseEvent *)
{
    closed();
}

void MainView::saveToFile()
{
    if (hasEmpty())
    {
        QMessageBox::warning(this, "Hiba!", "Nem lehet menteni, mert hiányoznak adatok!");
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this);
    if (filename == "")
    {
        return;
    }


    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);

    stream << _oneDimension->isChecked() << '\n';

    stream << _bottom->currentIndex() << '\n';
    if (_bottom->currentIndex() == 0)
    {
        stream << _partMinX->value() << " " << _partMaxX->value() << " " << _partCountX->value() << " " << _partTypeX->currentText() << '\n';
        stream << _partMinY->value() << " " << _partMaxY->value() << " " << _partCountY->value() << " " << _partTypeY->currentText()  << '\n';
    }
    if (_bottom->currentIndex() == 1)
    {
        stream << _part2CountX->value() << " " << _part2CountY->value() << '\n';

        for (int i = 0; i < _part2BaseX.size(); i++)
        {
            stream << _part2BaseX[i]->text() << " ";
        }
        stream << '\n';

        for (int i = 0; i < _part2BaseY.size(); i++)
        {
            stream << _part2BaseY[i]->text() << " ";
        }
        stream << '\n';
    }

    stream << _top->currentIndex() << '\n';
    if (_top->currentIndex() == 0)
    {
        stream << _funcInput->text()  << '\n';
    }
    if (_top->currentIndex() == 1)
    {
        for (int i = 0; i < _pointInput.size(); i++)
        {
            for (int j = 0; j < _pointInput[i].size(); j++)
            {
                stream << _pointInput[i][j]->text() << " ";
            }
            stream << '\n';
        }
    }

    file.close();
}

void MainView::loadFromFile()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if (filename == "")
    {
        return;
    }

    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    int dim;
    stream >> dim;

    int index;
    stream >> index;
    _bottom->setCurrentIndex(index);
    if (index == 0)
    {
        double min, max;
        int count;
        QString type;

        stream >> min >> max >> count >> type;
        _partMinX->setValue(min);
        _partMaxX->setValue(max);
        _partCountX->setValue(count);
        _partTypeX->setCurrentIndex((type == "Egyenletes")?(0):(1));

        stream >> min >> max >> count >> type;
        _partMinY->setValue(min);
        _partMaxY->setValue(max);
        _partCountY->setValue(count);
        _partTypeY->setCurrentIndex((type == "Egyenletes")?(0):(1));
     }
    if (index == 1)
    {
        int countX, countY;
        stream >> countX >> countY;

        _part2CountX->setValue(countX);
        _part2CountY->setValue(countY);

        for (int i = 0; i < _part2BaseX.size(); i++)
        {
            double tmp;
            stream >> tmp;
            _part2BaseX[i]->setText(QString::number(tmp, 'g', 4));
        }

        for (int i = 0; i < _part2BaseY.size(); i++)
        {
            double tmp;
            stream >> tmp;
            _part2BaseY[i]->setText(QString::number(tmp, 'g', 4));
        }

        partChangedX();
        partChangedY();
    }

    if (dim == 1)
    {
        _oneDimension->setChecked(true);
    }
    else
    {
        _oneDimension->setChecked(false);
    }
    dimensionChanged();

    stream >> index;
    _top->setCurrentIndex(index);
    if (index == 0)
    {
        QString func;
        stream >> func;
        _funcInput->setText(func);
    }
    if (index == 1)
    {
        for (int i = 0; i < _pointInput.size(); i++)
        {
            for (int j = 0; j < _pointInput[i].size(); j++)
            {
                double tmp;
                stream >> tmp;
                _pointInput[i][j]->setText(QString::number(tmp, 'f', 2));
            }
        }
    }


    file.close();
}

void MainView::showMessage(QString msg)
{
    if (_showSteps->isChecked())
        QMessageBox::information(this, "Következő lépés", msg);
    advance();
}

void MainView::showError(QString msg)
{
    QMessageBox::warning(this, "Hiba!", msg);
}

void MainView::helpClicked()
{
    _help->exec();
}
