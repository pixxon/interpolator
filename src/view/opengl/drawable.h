#ifndef DRAWABLE_H
#define DRAWABLE_H


#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>


#include <QVector>
#include <QVector3D>


namespace View
{
    namespace OpenGL
    {
        class Drawable
        {
            public:
                Drawable(QOpenGLShaderProgram*);
                ~Drawable();

                void addData(QVector3D, QVector3D);
                void init();
                void draw(GLenum);
                void clear();

            private:
                QOpenGLShaderProgram* _program;

                QOpenGLVertexArrayObject* _vao;
                QOpenGLBuffer* _posVbo;
                QOpenGLBuffer* _colVbo;

                QVector<QVector3D> _posData;
                QVector<QVector3D> _colData;
        };
    }
}

#endif // DRAWABLE_H
