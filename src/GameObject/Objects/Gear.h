#ifndef GEAR_H
#define GEAR_H

class Egg;
class SensoBox;
#include "GameObject2D.h"
class Gear : public GameObject2D
{
public:
	Gear() = delete;
	Gear(const Gear&) = delete;
	const Gear& operator = (const Gear&) = delete;
	~Gear();

	Gear(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Egg&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(SensorBox&, b2Contact*, const b2ContactImpulse*) override;
};

#endif GEAR_H