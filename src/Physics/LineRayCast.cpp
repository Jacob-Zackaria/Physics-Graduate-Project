#include "LineRayCast.h"


float32 LineRayCast::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction)
{
	fraction;
	point;
	normal;

	// Warning: there is no smarts in this demo: we don't test whether the fixture was already added...
	// This may or may not be an issue depending your particular situation
	lstFixtures.push_front(fixture);

	return 1;
}

void LineRayCast::ClearList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* pbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		pbox->color = Color::Type::Yellow;
	}

	lstFixtures.clear();
}

void LineRayCast::ProcessList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* pbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		pbox->color = Color::Type::Red;
	}
}

LineRayCast::LineRayCast()
{
}

LineRayCast::~LineRayCast()
{
}
