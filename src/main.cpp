#include "model/model.h"
#include "view/mainview.h"
#include "view/openglview.h"
#include "controller/controller.h"

#include <QApplication>
#include <QVector3D>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    View::MainView mainView;
    View::OpenGLView interView;
    interView.setWindowTitle("Interpoláció");
    View::OpenGLView funcView;
    funcView.setWindowTitle("Függvény");
    View::OpenGLView diffView;
    diffView.setWindowTitle("Hiba");
    Model::Model model;

    Controller::Controller controller(&mainView, &funcView, &interView, &diffView, &model);

    controller.start();

    return a.exec();
}
