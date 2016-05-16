#ifndef CAMERA_H
#define CAMERA_H


#include <QMatrix4x4>
#include <QVector3D>

namespace View
{
    namespace OpenGL
    {
        class Camera
        {
            public:
                Camera();
                Camera(QMatrix4x4, QMatrix4x4, QMatrix4x4);
                ~Camera();

                void setProj(QMatrix4x4);
                void setView(QMatrix4x4);
                void setWorld(QMatrix4x4);

                QMatrix4x4 getProj();
                QMatrix4x4 getView();
                QMatrix4x4 getWorld();
                QMatrix4x4 getWorldIT();
                QMatrix4x4 getMVP();

                void lookAt(QVector3D, QVector3D, QVector3D);
                static QMatrix4x4 perspective(double, double, double, double);

                void move(int);

            private:
                QMatrix4x4 _proj;
                QMatrix4x4 _view;
                QMatrix4x4 _world;

                QVector3D _eye;
                QVector3D _center;
                QVector3D _up;
        };
    }
}


#endif // CAMERA_H
