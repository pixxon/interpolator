#include "mainview.h"
#include <QHBoxLayout>

MainView::MainView(QWidget *parent) :
    QWidget(parent)
{
    button = new QPushButton("Render");
    input = new QLineEdit();
    QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));

    QHBoxLayout* layout = new QHBoxLayout();

    layout->addWidget(input);
    layout->addWidget(button);

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
