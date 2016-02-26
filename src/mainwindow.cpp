#include "mainwindow.h"
#include "glm/gtc/matrix_transform.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QOpenGLWidget(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    makeCurrent();
    glewInit();
    glClearColor(0.3, 0.2, 0.4, 0);

    program = new ShaderProgram();

    program->bindAttribute(0, "vs_in_pos");

    program->addShader(GL_VERTEX_SHADER, "../opengl/myVert.vert");
    program->addShader(GL_FRAGMENT_SHADER, "../opengl/myFrag.frag");

    program->linkProgram();

    drawable = new Drawable();
    drawable->setAttribute(0, 3);

    drawable->addData(0, {0.f, 0.f, 0.f});
    drawable->addData(0, {1.f, 0.f, 0.f});
    drawable->addData(0, {1.f, 0.f, 1.f});

    drawable->addData(0, {0.f, 0.f, 0.f});
    drawable->addData(0, {0.f, 0.f, 1.f});
    drawable->addData(0, {1.f, 0.f, 1.f});

    drawable->init();

    camera = new Camera();

    camera->setProj(glm::perspective(45.f, 640/480.f, 0.001f, 100.f));
    camera->setView(glm::lookAt(glm::vec3(5, 5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));
    camera->setWorld(glm::mat4(1.f));

    doneCurrent();
}

void MainWindow::paintGL()
{
    makeCurrent();
    program->programOn();

    glClear(GL_COLOR_BUFFER_BIT);

    program->setUniform("world", camera->getWorld());
    program->setUniform("view", camera->getView());
    program->setUniform("proj", camera->getProj());

    drawable->draw(GL_TRIANGLES, 0, 6);

    program->programOff();
    doneCurrent();
}
