#ifndef LINE_RAY_CAST_H
#define LINE_RAY_CAST_H

#include "GameObject2D.h"
#include <list>

class AABBRayCast : public b2QueryCallback
{
public:
	AABBRayCast();
	AABBRayCast(const AABBRayCast&) = delete;
	const AABBRayCast& operator = (const AABBRayCast&) = delete;
	~AABBRayCast();

	virtual bool ReportFixture(b2Fixture* fixture) override;

	void ClearList();
	void ProcessList();

private:
	using ListFixtures = std::list<b2Fixture*>;
	ListFixtures lstFixtures;

	GraphicsObject_Box* pbox;
};


#endif LINE_RAY_CAST_H