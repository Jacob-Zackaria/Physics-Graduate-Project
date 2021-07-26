#ifndef EGG_H
#define EGG_H

class Gear;

#include "GameObject2D.h"
#include "GameObjectCharacteristics.h"
class Egg : public GameObject2D
{
public:
	Egg() = delete;
	Egg(const Egg&) = delete;
	const Egg& operator = (const Egg&) = delete;
	~Egg();
	Egg(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Circle);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(Gear&, b2Contact*, const b2ContactImpulse*) override;

	void NextLevel();

	bool nextLevel;
};

#endif EGG_H