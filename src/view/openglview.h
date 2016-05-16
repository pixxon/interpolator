#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>


#include "opengl/drawable.h"
#include "opengl/camera.h"


namespace View
{
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
            void setTwoDimension(bool enabled);

        private:
            QOpenGLShaderProgram* _program;
            OpenGL::Camera _camera;
            OpenGL::Drawable* _surface;
            OpenGL::Drawable* _coord;
            OpenGL::Drawable* _ball;
            bool _twoDimension;
            bool _rotate;

            QVector<QVector3D> _ballPos;

            double _maxDist;

        private slots:
            void keyPressEvent(QKeyEvent*);
    };
}

#endif // OPENGLVIEW_H
