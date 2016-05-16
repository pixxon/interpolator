#include "openglview.h"

#include <QOpenGLShader>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QKeyEvent>
#include <QtMath>


namespace View
{
    OpenGLView::OpenGLView(QWidget *parent) :
        QOpenGLWidget(parent)
    {
        _program = new QOpenGLShaderProgram();
        _surface = new OpenGL::Drawable(_program);
        _coord = new OpenGL::Drawable(_program);
        _ball = new OpenGL::Drawable(_program);
        _twoDimension = false;
        _rotate = true;
        _maxDist = 0;
    }

    OpenGLView::~OpenGLView()
    {
        _surface->clear();
        _coord->clear();
        _ball->clear();


        delete _program;
        delete _surface;
        delete _ball;
        delete _coord;
    }

    void OpenGLView::initializeGL()
    {
        QOpenGLContext::currentContext()->functions()->glClearColor(1, 1, 1, 1);
        QOpenGLContext::currentContext()->functions()->glEnable(GL_DEPTH_TEST);
        QOpenGLContext::currentContext()->functions()->glLineWidth(2.f);

        _program->create();

        _program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex");
        _program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment");

        _program->link();
        _program->bind();

        _coord->addData(QVector3D(-1000, 0, 0), QVector3D(0, 0, 0));
        _coord->addData(QVector3D(1000, 0, 0), QVector3D(0, 0, 0));

        _coord->addData(QVector3D(0, -1000, 0), QVector3D(0, 0, 0));
        _coord->addData(QVector3D(0, 1000, 0), QVector3D(0, 0, 0));

        _coord->addData(QVector3D(0, 0, -1000), QVector3D(0, 0, 0));
        _coord->addData(QVector3D(0, 0, 1000), QVector3D(0, 0, 0));

        _coord->init();

        _program->bindAttributeLocation("vs_in_pos", 0);
        _program->bindAttributeLocation("vs_in_col", 1);

        _program->release();

        _camera.setProj(OpenGL::Camera::perspective(45.f, 640/480.f, 0.001f, 100.f));
    }


    void OpenGLView::paintGL()
    {
        QOpenGLContext::currentContext()->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        QMatrix4x4 tmp = _camera.getWorld();
        if (_twoDimension)
        {
            tmp.setToIdentity();

        }
        else if(_rotate)
        {
            tmp.rotate(1.f, 0.f, 1.f, 0.f);
        }

        _camera.setWorld(tmp);

        _program->bind();

        _program->setUniformValue("world", _camera.getWorld());
        _program->setUniformValue("view", _camera.getView());
        _program->setUniformValue("proj", _camera.getProj());

        _program->setUniformValue("coloring", 1);
        if (_twoDimension)
        {
            _surface->draw(GL_LINES);
        }
        else
        {
            _surface->draw(GL_QUADS);
        }

        _program->setUniformValue("coloring", 0);
        _coord->draw(GL_LINES);

        for (QVector3D pos: _ballPos)
        {
            QMatrix4x4 tmp = _camera.getWorld();
            tmp.translate(pos);
            _program->setUniformValue("world", tmp);
            _ball->draw(GL_QUADS);
        }

        _program->release();
    }

    void OpenGLView::resizeGL(int w, int h)
    {
        _camera.setProj(OpenGL::Camera::perspective(45.f, w/(double)h, 0.001f, 1000.f));
    }

    void OpenGLView::init()
    {
        if(_twoDimension)
        {
            _camera.lookAt(QVector3D(0, 0, _maxDist * 3), QVector3D(0, 0, 0), QVector3D(0, 1, 0));
        }
        else
        {
            _camera.lookAt(QVector3D(_maxDist * 3, _maxDist, _maxDist * 3), QVector3D(0, 0, 0), QVector3D(0, 1, 0));
        }

        show();

        makeCurrent();
        _program->bind();

        _ball->clear();
        const int N = 20;
        const double r = _maxDist/40;
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < N + 1; j++)
            {
                double u = (double)i / (double)N * M_PI * 2;
                double v = (double)j / (double)N * M_PI;
                _ball->addData(QVector3D(r*sin(v)*cos(u), r*sin(v)*sin(u), r*cos(v)), QVector3D(0.1, 0.1, 0.8));


                u = (double)(i + 1) / (double)N * M_PI * 2;
                v = (double)j / (double)N * M_PI;
                _ball->addData(QVector3D(r*sin(v)*cos(u), r*sin(v)*sin(u), r*cos(v)), QVector3D(0.1, 0.1, 0.8));


                u = (double)(i + 1) / (double)N * M_PI * 2;
                v = (double)(j + 1) / (double)N * M_PI;
                _ball->addData(QVector3D(r*sin(v)*cos(u), r*sin(v)*sin(u), r*cos(v)), QVector3D(0.1, 0.1, 0.8));


                u = (double)i / (double)N * M_PI * 2;
                v = (double)(j + 1) / (double)N * M_PI;
                _ball->addData(QVector3D(r*sin(v)*cos(u), r*sin(v)*sin(u), r*cos(v)), QVector3D(0.1, 0.1, 0.8));
            }
        }

        _ball->init();

        _surface->init();

        _program->release();
        doneCurrent();
    }

    void OpenGLView::clear()
    {
        _surface->clear();
        _ballPos.clear();
        hide();
    }

    void OpenGLView::addPoint(QVector3D pos, QVector3D col)
    {
        _maxDist = qMax<double>(_maxDist, qAbs(pos.x()));
        _maxDist = qMax<double>(_maxDist, qAbs(pos.y()));
        _maxDist = qMax<double>(_maxDist, qAbs(pos.z()));

        _surface->addData(pos, col);
    }

    void OpenGLView::addCommonPoint(QVector3D pos)
    {
        _ballPos.push_back(pos);
    }

    void OpenGLView::setTwoDimension(bool enabled)
    {
        hide();
        _twoDimension = enabled;
    }

    void OpenGLView::keyPressEvent(QKeyEvent* key)
    {
        switch (key->key())
        {
            case Qt::Key_Space:
                _rotate = !_rotate;
            break;
            case Qt::Key_W:
                _camera.move(1);
            break;
            case Qt::Key_S:
                _camera.move(-1);
            break;
            default:
            break;
        }
    }
}
