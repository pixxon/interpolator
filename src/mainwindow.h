#define GLM_FORCE_RADIANS
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "opengl/shaderprogram.h"
#include "opengl/drawable.h"
#include "opengl/camera.h"
#include <QOpenGLWidget>

class MainWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initializeGL();
    void paintGL();
private:
    Camera* camera;
    Drawable* drawable;
    ShaderProgram* program;
};

#endif // MAINWINDOW_H
