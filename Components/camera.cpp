#include "camera.h"
#include "GameState.h"

Camera::Camera()
{
	//edit
	projection = translate(960, 115) * scale(.5,.5);
}

mat3 Camera::getCameraMatrix()
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, GameState & gs)
{
	transform.m_position = lerp(transform.m_position,
		gs.player.transform.getGlobalPosition(), 0.3f);

	
}
