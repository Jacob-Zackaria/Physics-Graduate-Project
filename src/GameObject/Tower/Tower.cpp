#include "Tower.h"
#include "GameObjectMan.h"
#include "TowerFactory.h"
Tower::Tower(const float newX, const float newY, const int height)
	:
	baseX(newX),
	baseY(newY),
	towHeight(height)
{
}

Tower::~Tower()
{
}

