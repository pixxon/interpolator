#include "mainview.h"


#include <QLayout>
#include <QLayoutItem>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QDoubleValidator>


MainView::MainView(QWidget *parent) :
    QWidget(parent)
{
    initialize();
}

MainView::~MainView()
{
}

void MainView::initialize()
{
    //_top_page_1
    _top_page_1 = new QWidget();
    _func_input = new QLineEdit();

    QHBoxLayout* _top_page_1_layout = new QHBoxLayout();
    _top_page_1_layout->addWidget(_func_input);

    _top_page_1->setLayout(_top_page_1_layout);

    //_top_page_2
    _top_page_2 = new QWidget();

    _point_input_x_size = 0;
    _point_input_y_size = 0;

    //_top_pages
    QTabWidget* top = new QTabWidget();
    top->addTab(_top_page_1, "Függvény");
    top->addTab(_top_page_2, "Értékek");

    //_bottom_page_1
    _bottom_page_1 = new QWidget();
    _part_min_X = new QDoubleSpinBox();
    _part_min_X->setMinimum(-std::numeric_limits<double>::max());
    _part_min_X->setMaximum(std::numeric_limits<double>::max());

    _part_max_X = new QDoubleSpinBox();
    _part_max_X->setMinimum(-std::numeric_limits<double>::max());
    _part_max_X->setMaximum(std::numeric_limits<double>::max());

    _part_count_X = new QSpinBox();
    _part_count_X->setMaximum(10);
    QObject::connect(_part_count_X, SIGNAL(valueChanged(int)), this, SLOT(count_x_changed(int)));

    _part_type_X = new QComboBox();
    _part_type_X->addItems(QStringList({"Egyenletes", "Csebisev"}));

    _part_min_Y = new QDoubleSpinBox();
    _part_min_Y->setMinimum(-std::numeric_limits<double>::max());
    _part_min_Y->setMaximum(std::numeric_limits<double>::max());

    _part_max_Y = new QDoubleSpinBox();
    _part_max_Y->setMinimum(-std::numeric_limits<double>::max());
    _part_max_Y->setMaximum(std::numeric_limits<double>::max());

    _part_count_Y = new QSpinBox();
    _part_count_Y->setMaximum(10);
    QObject::connect(_part_count_Y, SIGNAL(valueChanged(int)), this, SLOT(count_y_changed(int)));

    _part_type_Y = new QComboBox();
    _part_type_Y->addItems(QStringList({"Egyenletes", "Csebisev"}));

    QGridLayout* _bottom_page_1_layout = new QGridLayout();

    _bottom_page_1_layout->addWidget(_part_min_X, 1, 0, 1, 1);
    _bottom_page_1_layout->addWidget(_part_max_X, 1, 1, 1, 1);
    _bottom_page_1_layout->addWidget(_part_count_X, 1, 2, 1, 1);
    _bottom_page_1_layout->addWidget(_part_type_X, 1, 3, 1, 1);

    _bottom_page_1_layout->addWidget(_part_min_Y, 2, 0, 1, 1);
    _bottom_page_1_layout->addWidget(_part_max_Y, 2, 1, 1, 1);
    _bottom_page_1_layout->addWidget(_part_count_Y, 2, 2, 1, 1);
    _bottom_page_1_layout->addWidget(_part_type_Y, 2, 3, 1, 1);


    _bottom_page_1->setLayout(_bottom_page_1_layout);

    //_bottom_page_2
    _bottom_page_2 = new QWidget();

    //_bottom_pages
    QTabWidget* bottom = new QTabWidget();
    bottom->addTab(_bottom_page_1, "Eloszlás");
    bottom->addTab(_bottom_page_2, "Alappontok");

    //_button
    _render_button = new QPushButton("Render");
    QObject::connect(_render_button, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));

    //_all
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(bottom);
    layout->addWidget(top);
    layout->addWidget(_render_button);

    setLayout(layout);
}

void MainView::buttonClick()
{
    try
    {
        emit partXSet(_part_min_X->value(), _part_max_X->value(), _part_count_X->value());
        emit partYSet(_part_min_Y->value(), _part_max_Y->value(), _part_count_X->value());

        emit inputSet(_func_input->text());
    }
    catch(std::exception& ex)
    {
        _func_input->setText(ex.what());
    }
}

void MainView::count_x_changed(int value)
{
    _point_input_x_size = value;

    QLayout* layout = _top_page_2->layout();
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

    QGridLayout* _top_page_2_layout = new QGridLayout();

    _point_input.resize(_point_input_x_size);
    for (int i = 0; i < _point_input.size(); i++)
    {
        _point_input[i].resize(_point_input_y_size);
        for (int j = 0; j < _point_input[i].size(); j++)
        {
           _point_input[i][j] = new QLineEdit();
           _point_input[i][j]->setValidator(new QDoubleValidator());
           _top_page_2_layout->addWidget(_point_input[i][j], i, j, 1, 1);
        }
    }

    _top_page_2->setLayout(_top_page_2_layout);
}

void MainView::count_y_changed(int value)
{
    QLayout* layout = _top_page_2->layout();
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

    _point_input_y_size = value;

    QGridLayout* _top_page_2_layout = new QGridLayout();
    _point_input.resize(_point_input_x_size);
    for (int i = 0; i < _point_input.size(); i++)
    {
        _point_input[i].resize(_point_input_y_size);
        for (int j = 0; j < _point_input[i].size(); j++)
        {
           _point_input[i][j] = new QLineEdit();
           _point_input[i][j]->setValidator(new QDoubleValidator());
           _top_page_2_layout->addWidget(_point_input[i][j], i, j, 1, 1);
        }
    }

    _top_page_2->setLayout(_top_page_2_layout);
}
