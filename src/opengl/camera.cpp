#include "camera.h"

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

QMatrix4x4 Camera::lookAt(QVector3D eye, QVector3D center, QVector3D up)
{
    QMatrix4x4 res;
    res.lookAt(eye, center, up);
    return res;
}

QMatrix4x4 Camera::perspective(float angle, float ratio, float near, float far)
{
    QMatrix4x4 res;
    res.perspective(angle, ratio, near, far);
    return res;
}
