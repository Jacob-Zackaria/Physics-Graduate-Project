#ifndef GLASS_H
#define GLASS_H

#include "GameObject2D.h"
#include "GameObjectCharacteristics.h"
class Glass : public GameObject2D, public GameObjectCharacteristics
{
public:
	Glass() = delete;
	Glass(const Glass&) = delete;
	const Glass& operator = (const Glass&) = delete;
	~Glass();
	Glass(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);
	Glass(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(SensorBox&, b2Contact*, const b2ContactImpulse*) override;

	virtual void ReduceHealth(const float newVal) override;
};

#endif GLASS_H