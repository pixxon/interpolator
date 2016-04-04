#include "openglview.h"

#include <QOpenGLShader>
#include <QOpenGLFunctions>
#include <QOpenGLContext>

OpenGLView::OpenGLView(QWidget *parent) :
    QOpenGLWidget(parent)
{
    _program = new QOpenGLShaderProgram();
    _surface = new Drawable(_program);
    _coord = new Drawable(_program);
}

OpenGLView::~OpenGLView()
{
}

void OpenGLView::addPointToSurface(QVector3D pos, QVector3D col)
{
    _surface->addData(pos, col);
}

void OpenGLView::initializeGL()
{
    QOpenGLContext::currentContext()->functions()->glClearColor(1, 1, 1, 1);
    QOpenGLContext::currentContext()->functions()->glEnable(GL_DEPTH_TEST);

    _program->create();

    _program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex");
    _program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment");

    _program->link();
    _program->bind();

    _coord->addData({-100, 0, 0}, {1, 1, 1});
    _coord->addData({100, 0, 0}, {1, 1, 1});

    _coord->addData({0, -100, 0}, {1, 1, 1});
    _coord->addData({0, 100, 0}, {1, 1, 1});

    _coord->addData({0, 0, -100}, {1, 1, 1});
    _coord->addData({0, 0, 100}, {1, 1, 1});

    _coord->init();

    _program->bindAttributeLocation("vs_in_pos", 0);
    _program->bindAttributeLocation("vs_in_col", 1);

    _program->release();

    _camera.setProj(Camera::perspective(45.f, 640/480.f, 0.001f, 100.f));
}

void OpenGLView::paintGL()
{
    _camera.setView(Camera::lookAt(QVector3D(10, 2, 10), QVector3D(0, 0, 0), QVector3D(0, 1, 0)));

    QOpenGLContext::currentContext()->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 tmp = _camera.getWorld();
    tmp.rotate(1.f, 0.f, 1.f, 0.f);
    _camera.setWorld(tmp);

    _program->bind();

    _program->setUniformValue("world", _camera.getWorld());
    _program->setUniformValue("view", _camera.getView());
    _program->setUniformValue("proj", _camera.getProj());

    _surface->draw(GL_QUADS);
    _coord->draw(GL_LINES);

    _program->release();
}

void OpenGLView::resizeGL(int w, int h)
{
    _camera.setProj(Camera::perspective(45.f, w/(float)h, 0.001f, 1000.f));
}

void OpenGLView::init()
{
    show();

    makeCurrent();
    _program->bind();

    _surface->init();

    _program->release();
    doneCurrent();
}

void OpenGLView::clear()
{
    _surface->clear();

    hide();
}
