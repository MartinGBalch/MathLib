#include "camera.h"
#include "GameState.h"

Camera::Camera()
{
	//edit
	projection = translate(600, 600) * scale(.5, .5);
}

mat3 Camera::getCameraMatrix()
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, GameState & gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();
}
