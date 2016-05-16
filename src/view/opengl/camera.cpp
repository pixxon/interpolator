#include "camera.h"


namespace View
{
    namespace OpenGL
    {
        Camera::Camera()
        {
        }

        Camera::Camera(QMatrix4x4 proj, QMatrix4x4 view, QMatrix4x4 world)
        {
            _proj = proj;
            _view = view;
            _world = world;
        }

        Camera::~Camera()
        {
        }

        void Camera::setProj(QMatrix4x4 proj)
        {
            _proj = proj;
        }

        void Camera::setView(QMatrix4x4 view)
        {
            _view = view;
        }

        void Camera::setWorld(QMatrix4x4 world)
        {
            _world = world;
        }

        QMatrix4x4 Camera::getProj()
        {
            return _proj;
        }

        QMatrix4x4 Camera::getView()
        {
            return _view;
        }

        QMatrix4x4 Camera::getWorld()
        {
            return _world;
        }

        QMatrix4x4 Camera::getWorldIT()
        {
            return _world.inverted().transposed();
        }

        QMatrix4x4 Camera::getMVP()
        {
            return _proj * _view * _world;
        }

        void Camera::lookAt(QVector3D eye, QVector3D center, QVector3D up)
        {
            _eye = eye;
            _center = center;
            _up = up;

            QMatrix4x4 res;
            res.lookAt(eye, center, up);
            _view = res;
        }

        QMatrix4x4 Camera::perspective(double angle, double ratio, double near, double far)
        {
            QMatrix4x4 res;
            res.perspective(angle, ratio, near, far);
            return res;
        }

        void Camera::move(int dir)
        {
            if (dir == 1)
            {
                _eye += (_center - _eye) / 4.f;
            }
            if (dir == -1)
            {
                _eye -= (_center - _eye) / 3.f;
            }

            QMatrix4x4 res;
            res.lookAt(_eye, _center, _up);
            _view = res;
        }
    }
}
