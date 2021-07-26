#ifndef MINION_PIG_H
#define MINION_PIG_H

#include "GameObject2D.h"
#include "GameObjectCharacteristics.h"
class MinionPig : public GameObject2D, public GameObjectCharacteristics
{
public:
	MinionPig() = delete;
	MinionPig(const MinionPig&) = delete;
	const MinionPig& operator = (const MinionPig&) = delete;
	~MinionPig();
	MinionPig(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Wood&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Glass&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Stone&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*) override;

	virtual void ReduceHealth(const float newVal) override;

	bool impact;
};

#endif MINION_PIG_H