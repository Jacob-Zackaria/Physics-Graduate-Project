#ifndef RED_BIRD_H
#define RED_BIRD_H

#include "Bird.h"
#include "GameObjectCharacteristics.h"
class RedBird : public Bird, public GameObjectCharacteristics
{
public:
	RedBird() = delete;
	RedBird(const RedBird&) = delete;
	const RedBird& operator = (const RedBird&) = delete;
	virtual ~RedBird();
	RedBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

	virtual void Update(float t) override;
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Wood& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Stone& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Glass& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(CollisionObjectBox& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(MinionPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(KingPig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

	virtual void ReduceHealth(const float newVal) override;

};

#endif RED_BIRD_H