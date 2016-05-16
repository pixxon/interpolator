#include "drawable.h"

#include <QOpenGLContext>
#include <QOpenGLFunctions>

namespace View
{
    namespace OpenGL
    {
        Drawable::Drawable(QOpenGLShaderProgram* program):
            _program(program)
        {
            _vao = new QOpenGLVertexArrayObject();
            _posVbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
            _colVbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);

        }

        Drawable::~Drawable()
        {
            _posVbo->destroy();
            _colVbo->destroy();
            _vao->destroy();

            delete _posVbo;
            delete _colVbo;
            delete _vao;
        }

        void Drawable::addData(QVector3D pos, QVector3D col)
        {
            _posData.push_back(pos);
            _colData.push_back(col);
        }

        void Drawable::init()
        {
            _vao->create();
            _vao->bind();

            _posVbo->create();
            _posVbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
            _posVbo->bind();
            _posVbo->allocate(_posData.constBegin(), _posData.size() * sizeof(QVector3D));

            _program->setAttributeBuffer(0, GL_FLOAT, 0, 3);
            _program->enableAttributeArray(0);
            _posVbo->release();

            _colVbo->create();
            _colVbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
            _colVbo->bind();
            _colVbo->allocate(_colData.constBegin(), _colData.size() * sizeof(QVector3D));

            _program->setAttributeBuffer(1, GL_FLOAT, 0, 3);
            _program->enableAttributeArray(1);
            _colVbo->release();

            _vao->release();
        }

        void Drawable::clear()
        {
            _vao->destroy();
            _posVbo->destroy();
            _colVbo->destroy();

            _posData.clear();
            _colData.clear();
        }

        void Drawable::draw(GLenum mode)
        {
            _vao->bind();


            QOpenGLContext::currentContext()->functions()->glDrawArrays(mode, 0, _posData.size() * 3);

            _vao->release();
        }
    }
}
