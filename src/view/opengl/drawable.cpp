#include "drawable.h"

#include <QOpenGLContext>
#include <QOpenGLFunctions>

Drawable::Drawable(QOpenGLShaderProgram* program):
    _program(program)
{
    _vao = new QOpenGLVertexArrayObject();
    _pos_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    _col_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);

}

Drawable::~Drawable()
{
    _pos_vbo->destroy();
    _col_vbo->destroy();
    _vao->destroy();

    delete _pos_vbo;
    delete _col_vbo;
    delete _vao;
}

void Drawable::addData(QVector3D pos, QVector3D col)
{
    _pos_data.push_back(pos);
    _col_data.push_back(col);
}

void Drawable::init()
{
    _vao->create();
    _vao->bind();

    _pos_vbo->create();
    _pos_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
    _pos_vbo->bind();
    _pos_vbo->allocate(_pos_data.constBegin(), _pos_data.size() * sizeof(QVector3D));

    _program->setAttributeBuffer(0, GL_FLOAT, 0, 3);
    _program->enableAttributeArray(0);
    _pos_vbo->release();

    _col_vbo->create();
    _col_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
    _col_vbo->bind();
    _col_vbo->allocate(_col_data.constBegin(), _col_data.size() * sizeof(QVector3D));

    _program->setAttributeBuffer(1, GL_FLOAT, 0, 3);
    _program->enableAttributeArray(1);
    _col_vbo->release();

    _vao->release();
}

void Drawable::clear()
{
    _vao->destroy();
    _pos_vbo->destroy();
    _col_vbo->destroy();

    _pos_data.clear();
    _col_data.clear();
}

void Drawable::draw(GLenum mode)
{
    _vao->bind();

    QOpenGLContext::currentContext()->functions()->glDrawArrays(mode, 0, _pos_data.size() * 3);

    _vao->release();
}
