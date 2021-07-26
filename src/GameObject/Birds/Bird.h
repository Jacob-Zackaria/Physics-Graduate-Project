#ifndef BIRD_H
#define BIRD_H

#include "GameObject2D.h"
#include "ExplosionFeathers.h"

class Bird : public GameObject2D
{
public:
	enum class BirdState
	{
		DRAGGED,
		NORMAL,
		FLYING,
		IMPACT
	};

	Bird() = delete;
	Bird(const Bird&) = delete;
	const Bird& operator = (const Bird&) = delete;
	virtual ~Bird();
	Bird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);
	Bird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Box);

	virtual void Update(float t) override;

	// Data
	BirdState bState;
	ExplosionFeathers explosionFeathers;
};

#endif BIRD_H