#include "Platform.h"
#include "PhysicsManager.h"
Platform::Platform(GameObject2D* frame, GameObject2D* platform, float lowPoint, float highPoint, b2Vec2 axis)
	:
	pPlat(platform),
	dist(0.0f)
{
	frame->GetBody()->GetFixtureList()->SetSensor(true);
	platform->GetBody()->SetType(b2BodyType::b2_dynamicBody);

	//bpos
	bPos = frame->GetBody()->GetPosition();

	// Add Prismatic Joint
	b2PrismaticJointDef pjdef;
	pjdef.bodyA = frame->GetBody();
	pjdef.bodyB = platform->GetBody();
	pjdef.collideConnected = false;
	pjdef.localAnchorA = frame->GetBody()->GetLocalPoint(platform->GetBody()->GetWorldCenter());
	pjdef.localAnchorB = b2Vec2(0, 0);
	pjdef.localAxisA = axis;

	pjdef.enableLimit = true;
	pjdef.upperTranslation = highPoint; // in meters!
	pjdef.lowerTranslation = lowPoint; // in meters!
	pjdef.enableMotor = true;

	pPrisJoint = (b2PrismaticJoint*)PhysicsManager::GetWorld()->CreateJoint(&pjdef);
}

Platform::~Platform()
{
}

const void Platform::ComputePlatformDistance()
{
	dist =  (pPlat->GetBody()->GetPosition() - bPos).LengthSquared();
}

const float Platform::GetPlatformDistance() const
{
	return dist;
}

void Platform::SetMotorSpeed(const float newSpeed)
{
	pPrisJoint->SetMotorSpeed(newSpeed);
}

void Platform::SetMaxMotorForce(const float force)
{
	pPrisJoint->SetMaxMotorForce(force);
}
