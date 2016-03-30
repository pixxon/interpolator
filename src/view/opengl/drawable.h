#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include <QVector>
#include <QVector3D>

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
    QOpenGLBuffer* _pos_vbo;
    QOpenGLBuffer* _col_vbo;

    QVector<QVector3D> _pos_data;
    QVector<QVector3D> _col_data;
};

#endif // DRAWABLE_H
