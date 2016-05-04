#include "model/model.h"
#include "view/mainview.h"
#include "view/openglview.h"
#include "controller/controller.h"

#include <QApplication>
#include <QVector3D>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainView mainView;
    OpenGLView interView;
    interView.setWindowTitle("Interpoláció");
    OpenGLView funcView;
    funcView.setWindowTitle("Függvény");
    Model model;

    Controller controller(&mainView, &funcView, &interView, &model);

    controller.start();

    return a.exec();
}
