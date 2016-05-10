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

    void init();
    void clear();
    void addPoint(QVector3D, QVector3D);
    void addCommonPoint(QVector3D);
    void setOneDimension(bool enabled);

private:
    QOpenGLShaderProgram* _program;
    Camera _camera;
    Drawable* _surface;
    Drawable* _coord;
    Drawable* _ball;
    bool _oneDimension;
    bool _rotate;

    QVector<QVector3D> _ballPos;

    double _maxDist;

private slots:
    void keyPressEvent(QKeyEvent*);
};

#endif // OPENGLVIEW_H
