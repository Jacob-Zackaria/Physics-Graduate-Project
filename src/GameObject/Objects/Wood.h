#ifndef WOOD_H
#define WOOD_H

#include "GameObject2D.h"
#include "GameObjectCharacteristics.h"
class Wood : public GameObject2D, public GameObjectCharacteristics
{
public:
	Wood() = delete;
	Wood(const Wood&) = delete;
	const Wood& operator = (const Wood&) = delete;
	~Wood();
	Wood(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);
	Wood(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Tri* graphicsObject_Tri);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(MinionPig&, b2Contact*, const b2ContactImpulse*) override;
	virtual void CollideVisit(KingPig&, b2Contact*, const b2ContactImpulse*) override;

	virtual void ReduceHealth(const float newVal) override;
};

#endif WOOD_H