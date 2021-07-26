#include "AABBRayCast.h"
#include "Visualizer.h"

AABBRayCast::AABBRayCast()
{
	pbox = new GraphicsObject_Box(Rect(0, 0, 1, 1));
}

AABBRayCast::~AABBRayCast()
{
	delete pbox;
}

bool AABBRayCast::ReportFixture(b2Fixture* fixture)
{
	lstFixtures.push_front(fixture);

	/*
	// Debug to inspect the gap issue
	b2AABB ab = (*lstFixtures.begin())->GetAABB(0);
	//*/

	return true;
}

void AABBRayCast::ClearList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* pNbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		pNbox->color = Color::Type::Yellow;
	}

	lstFixtures.clear();

	// Clearing the Visualizer's AABB
	Visualizer::ClearAABBs();
}

void AABBRayCast::ProcessList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* pNbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		pNbox->color = Color::Type::Red;

		// Making the AABB visible for demo
		b2AABB ab = pgobj->GetBody()->GetFixtureList()->GetAABB(0);
		Visualizer::AddAABB(ab, Color::Type::Black);
	}
}
