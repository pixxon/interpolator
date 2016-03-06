#include "model.h"
#include "mainview.h"
#include "openglview.h"

#include <QApplication>
#include <QVector3D>
#include <QDebug>
#include <regex>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainView mainView;
    OpenGLView openGLView;
    Model model;


    QObject::connect(&mainView, SIGNAL(inputSet(QString)), &model, SLOT(setInput(QString)));
    QObject::connect(&model, SIGNAL(init()), &openGLView, SLOT(init()));
    QObject::connect(&model, SIGNAL(addData(QVector3D,QVector3D)), &openGLView, SLOT(addPointToSurface(QVector3D,QVector3D)));
    QObject::connect(&model, SIGNAL(render()), &openGLView, SLOT(render()));
    mainView.show();
    openGLView.hide();




    return a.exec();
}
