#ifndef WHITE_BIRD_H
#define WHITE_BIRD_H

#include "Bird.h"

class WhiteBird : public Bird
{
public:
	WhiteBird() = delete;
	WhiteBird(const WhiteBird&) = delete;
	const WhiteBird& operator = (const WhiteBird&) = delete;
	virtual ~WhiteBird();
	WhiteBird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle);

};

#endif WHITE_BIRD_H