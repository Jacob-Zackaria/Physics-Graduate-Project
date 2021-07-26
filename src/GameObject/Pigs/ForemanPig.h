#ifndef FOREMAN_PIG_H
#define FOREMAN_PIG_H

#include "GameObject2D.h"

class ForemanPig : public GameObject2D
{
public:
	ForemanPig() = delete;
	ForemanPig(const ForemanPig&) = delete;
	const ForemanPig& operator = (const ForemanPig&) = delete;
	~ForemanPig();
	ForemanPig(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

};

#endif FOREMAN_PIG_H