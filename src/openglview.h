#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

#include "opengl/drawable.h"
#include "opengl/camera.h"

class OpenGLView : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLView(QWidget *parent = 0);
    ~OpenGLView();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    QOpenGLShaderProgram* _program;
    Camera _camera;
    Drawable* _surface;
    Drawable* _coord;

public slots:
    void init();
    void render();
    void addPointToSurface(QVector3D, QVector3D);

signals:
};

#endif // OPENGLVIEW_H
