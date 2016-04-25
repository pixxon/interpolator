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
    OpenGLView inter_view;
    inter_view.setWindowTitle("Interpoláció");
    OpenGLView func_view;
    func_view.setWindowTitle("Függvény");
    Model model;

    Controller controller(&mainView, &func_view, &inter_view, &model);

    controller.start();

    return a.exec();
}
