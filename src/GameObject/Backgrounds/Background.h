#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject2D.h"

class Background : public GameObject2D
{
public:
	Background() = delete;
	Background(const Background&) = delete;
	const Background& operator = (const Background&) = delete;
	~Background();
	Background(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject);

};

#endif BACKGROUND_H