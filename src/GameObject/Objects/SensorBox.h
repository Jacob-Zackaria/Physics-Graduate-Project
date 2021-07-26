#ifndef SENSOR_BOX_H
#define SENSOR_BOX_H

#include "GameObject2D.h"

class SensorBox : public GameObject2D
{
public:
	SensorBox() = delete;
	SensorBox(const SensorBox&) = delete;
	const SensorBox& operator = (const SensorBox&) = delete;
	~SensorBox();
	SensorBox(GameObjectName::Name name, GraphicsObject_Box* graphicsObject_Box);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Gear&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Glass&, b2Contact*, const b2ContactImpulse*) override;
};

#endif SENSOR_BOX_H