#include "mainview.h"
#include <QGridLayout>

MainView::MainView(QWidget *parent) :
    QWidget(parent)
{
    button = new QPushButton("Render");
    QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));

    input = new QLineEdit();

    minSlider = new QSlider(Qt::Horizontal);
    minSlider->setTickPosition(QSlider::TicksBelow);

    maxSlider = new QSlider(Qt::Horizontal);
    maxSlider->setTickPosition(QSlider::TicksBelow);
    maxSlider->setInvertedAppearance(true);

    counter = new QSpinBox();

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(input, 0, 0, 1, 2);
    layout->addWidget(button, 0, 2, 1, 1);
    layout->addWidget(minSlider, 1, 0, 1, 2);
    layout->addWidget(maxSlider, 2, 0, 1, 2);
    layout->addWidget(counter, 1, 2, 2, 1);

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
