#include "model/model.h"
#include "view/mainview.h"
#include "view/openglview.h"

#include <QApplication>
#include <QVector3D>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainView mainView;
    OpenGLView inter_view;
    inter_view.setWindowTitle("Interpoláció");
    OpenGLView func_view;
    func_view.setWindowTitle("Függvény");
    Model model;


    QObject::connect(&mainView, SIGNAL(inputSet(QString)), &model, SLOT(setInput(QString)));
	QObject::connect(&mainView, SIGNAL(inputSet(QVector<QVector<double>>)), &model, SLOT(setInput(QVector<QVector<double>>)));
    QObject::connect(&mainView, SIGNAL(partXSet(double, double, int, QString)), &model, SLOT(setPartX(double,double,int, QString)));
    QObject::connect(&mainView, SIGNAL(partYSet(double, double, int, QString)), &model, SLOT(setPartY(double,double,int, QString)));
    QObject::connect(&model, SIGNAL(part_changed(QVector<double>,QVector<double>)), &mainView, SLOT(part_changed(QVector<double>,QVector<double>)));

    QObject::connect(&model, SIGNAL(init()), &inter_view, SLOT(init()));
    QObject::connect(&model, SIGNAL(addData(QVector3D,QVector3D)), &inter_view, SLOT(addPointToSurface(QVector3D,QVector3D)));
    QObject::connect(&model, SIGNAL(render()), &inter_view, SLOT(update()));
    QObject::connect(&model, SIGNAL(clear()), &inter_view, SLOT(clear()));

    QObject::connect(&model, SIGNAL(init()), &func_view, SLOT(init()));
    QObject::connect(&model, SIGNAL(addData2(QVector3D,QVector3D)), &func_view, SLOT(addPointToSurface(QVector3D,QVector3D)));
    QObject::connect(&model, SIGNAL(render()), &func_view, SLOT(update()));
    QObject::connect(&model, SIGNAL(clear()), &func_view, SLOT(clear()));

    mainView.show();

    return a.exec();
}
