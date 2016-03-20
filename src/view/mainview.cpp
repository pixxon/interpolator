#include "mainview.h"
#include <QGridLayout>

MainView::MainView(QWidget *parent) :
    QWidget(parent)
{
    button = new QPushButton("Render");
    QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));

    input = new QLineEdit();

    minX = new QDoubleSpinBox();
    minX->setMinimum(-std::numeric_limits<double>::max());
    minX->setMaximum(std::numeric_limits<double>::max());
    maxX = new QDoubleSpinBox();
    maxX->setMinimum(-std::numeric_limits<double>::max());
    maxX->setMaximum(std::numeric_limits<double>::max());
    countX = new QSpinBox();
    countX->setMaximum(std::numeric_limits<int>::max());

    minY = new QDoubleSpinBox();
    minY->setMinimum(-std::numeric_limits<double>::max());
    minY->setMaximum(std::numeric_limits<double>::max());
    maxY = new QDoubleSpinBox();
    maxY->setMinimum(-std::numeric_limits<double>::max());
    maxY->setMaximum(std::numeric_limits<double>::max());
    countY = new QSpinBox();
    countY->setMaximum(std::numeric_limits<int>::max());

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(input, 0, 0, 1, 2);
    layout->addWidget(button, 0, 2, 1, 1);

    layout->addWidget(minX, 1, 0, 1, 1);
    layout->addWidget(maxX, 1, 1, 1, 1);
    layout->addWidget(countX, 1, 2, 1, 1);

    layout->addWidget(minY, 2, 0, 1, 1);
    layout->addWidget(maxY, 2, 1, 1, 1);
    layout->addWidget(countY, 2, 2, 1, 1);

    setLayout(layout);
}

MainView::~MainView()
{
    delete button;
    delete input;
}

void MainView::buttonClick()
{
    try
    {
        emit inputSet(input->text());
    }
    catch(std::exception& ex)
    {
        input->setText(ex.what());
    }
}
