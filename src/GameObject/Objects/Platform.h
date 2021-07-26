#ifndef PLATFORM_H
#define PLATFORM_H

#include "GameObject2D.h"
class Platform
{
public:
	Platform(GameObject2D* frame, GameObject2D* platform, float lowPoint, float highPoint, b2Vec2 axis);
	Platform(const Platform&) = delete;
	const Platform& operator = (const Platform&) = delete;
	~Platform();

	const void ComputePlatformDistance();
	const float GetPlatformDistance() const;
	void SetMotorSpeed(const float newSpeed);
	void SetMaxMotorForce(const float force);

private:
	b2PrismaticJoint* pPrisJoint;
	b2Vec2 bPos;
	GameObject2D* pPlat;
	float dist;
};

#endif PLATFORM_H