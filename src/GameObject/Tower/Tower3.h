#ifndef TOWER_THREE_H
#define TOWER_THREE_H

#include "GameObject2D.h"
#include "Tower.h"
class Tower3 : public Tower
{
public:
	Tower3(const float newX, const float newY, const int height);
	Tower3(const Tower3&) = delete;
	const Tower3& operator = (const Tower3&) = delete;
	virtual ~Tower3();

	void Build() override;
	void Destroy() override;
};

#endif TOWER_THREE_H