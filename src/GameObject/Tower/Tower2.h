#ifndef TOWER_TWO_H
#define TOWER_TWO_H

#include "GameObject2D.h"
#include "Tower.h"
class Tower2 : public Tower
{
public:
	Tower2(const float newX, const float newY, const int height);
	Tower2(const Tower2&) = delete;
	const Tower2& operator = (const Tower2&) = delete;
	virtual ~Tower2();

	void Build() override;
	void Destroy() override;
};

#endif TOWER_TWO_H