#include "camera.h"

Camera::Camera()
{
}

Camera::Camera(glm::mat4 proj, glm::mat4 view, glm::mat4 world)
{
	_proj = proj;
	_view = view;
	_world = world;
}

Camera::~Camera()
{
}

void Camera::setProj(glm::mat4 proj)
{
	_proj = proj;
}

void Camera::setView(glm::mat4 view)
{
	_view = view;
}

void Camera::setWorld(glm::mat4 world)
{
	_world = world;
}

glm::mat4 Camera::getProj()
{
	return _proj;
}

glm::mat4 Camera::getView()
{
	return _view;
}

glm::mat4 Camera::getWorld()
{
	return _world;
}

glm::mat4 Camera::getWorldIT()
{
	return glm::transpose( glm::inverse( _world ) );
}

glm::mat4 Camera::getMVP()
{
	return _proj * _view * _world;
}