#ifndef CORPORAL_PIG_H
#define CORPORAL_PIG_H

#include "GameObject2D.h"

class CorporalPig : public GameObject2D
{
public:
	CorporalPig() = delete;
	CorporalPig(const CorporalPig&) = delete;
	const CorporalPig& operator = (const CorporalPig&) = delete;
	~CorporalPig();
	CorporalPig(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

};

#endif CORPORAL_PIG_H