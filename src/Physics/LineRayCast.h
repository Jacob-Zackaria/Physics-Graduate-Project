#ifndef LINE_RAY_CAST_H
#define LINE_RAY_CAST_H

#include "GameObject2D.h"
#include <list>

class LineRayCast : public b2RayCastCallback
{
public:
	LineRayCast();
	LineRayCast(const LineRayCast&) = delete;
	const LineRayCast& operator = (const LineRayCast&) = delete;
	~LineRayCast();

	virtual float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) override;

	void ClearList();
	void ProcessList();

private:
	using ListFixtures = std::list<b2Fixture*>;
	ListFixtures lstFixtures;

};


#endif LINE_RAY_CAST_H