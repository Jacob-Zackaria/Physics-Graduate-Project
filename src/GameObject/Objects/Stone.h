#ifndef STONE_H
#define STONE_H

#include "GameObject2D.h"
#include "GameObjectCharacteristics.h"
class Stone : public GameObject2D, public GameObjectCharacteristics
{
public:
	Stone() = delete;
	Stone(const Stone&) = delete;
	const Stone& operator = (const Stone&) = delete;
	~Stone();
	Stone(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);
	Stone(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*) override;

	virtual void ReduceHealth(const float newVal) override;
};

#endif STONE_H