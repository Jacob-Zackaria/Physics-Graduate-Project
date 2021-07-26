#ifndef TOWER_H
#define TOWER_H

#include "GameObject2D.h"

class Tower
{
public:
	Tower(const float newX, const float newY, const int height);
	Tower(const Tower&) = delete;
	const Tower& operator = (const Tower&) = delete;
	virtual ~Tower();

	virtual void Build() = 0;
	virtual void Destroy() = 0;

protected:
	float baseX;
	float baseY;
	int towHeight;
};

#endif TOWER_H