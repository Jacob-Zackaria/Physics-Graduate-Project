#ifndef TOWER_ONE_H
#define TOWER_ONE_H

#include "GameObject2D.h"
#include "Tower.h"
class Tower1 : public Tower
{
public:
	Tower1(const float newX, const float newY, const int height);
	Tower1(const Tower1&) = delete;
	const Tower1& operator = (const Tower1&) = delete;
	virtual ~Tower1();

	void Build() override;
	void Destroy() override;
};

#endif TOWER_ONE_H