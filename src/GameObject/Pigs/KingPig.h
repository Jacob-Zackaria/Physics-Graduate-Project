#ifndef KING_PIG_H
#define KING_PIG_H

#include "GameObject2D.h"
#include "GameObjectCharacteristics.h"
class KingPig : public GameObject2D, public GameObjectCharacteristics
{
public:
	KingPig() = delete;
	KingPig(const KingPig&) = delete;
	const KingPig& operator = (const KingPig&) = delete;
	~KingPig();
	KingPig(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Wood&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Glass&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(Stone&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*) override;

	virtual void ReduceHealth(const float newVal) override;
};

#endif KING_PIG_H