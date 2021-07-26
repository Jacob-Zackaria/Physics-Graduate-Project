#include "AABBQuery.h"
#include "InputManager.h"
#include "Visualizer.h"
#include "PhysicsManager.h"
AABBQuery::AABBQuery()
	:
	pRayCast(new AABBRayCast())
{
}

AABBQuery::~AABBQuery()
{
	delete pRayCast;
}

void AABBQuery::Update()
{
	static bool LeftButtonDown = false;
	static b2Vec2 startPos;
	static b2Vec2 endPos;

	if ((InputManager::GetMouseState() == InputManager::MouseState::LEFT) && !LeftButtonDown)
	{
		// begin area
		startPos = InputManager::GetMouseWorld();
		endPos = startPos;
		//DebugMsg::out("Area: Begin\n");
		LeftButtonDown = true;

		pRayCast->ClearList();
	}
	else if ((InputManager::GetMouseState() == InputManager::MouseState::LEFT) && LeftButtonDown)
	{
		// opposite area corner
		endPos = InputManager::GetMouseWorld();

		//DebugMsg::out("Area: (%.2f, %.2f) - (%.2f, %.2f)\n", startPos.x, startPos.y, endPos.x, endPos.y);
		LeftButtonDown = true;
	}
	else if (!(InputManager::GetMouseState() == InputManager::MouseState::LEFT) && LeftButtonDown)
	{
		// end area select
		//DebugMsg::out("Area: End\n");
		LeftButtonDown = false;
	}

	// This was moved outside the 'if' above so that the area test can persist over time
	// This aspect may not be relevant to your application
	if ((endPos - startPos).LengthSquared() > FLT_EPSILON)
	{
		pRayCast->ClearList();

		b2Vec2 lower(fmin(startPos.x, endPos.x), fmin(startPos.y, endPos.y));
		b2Vec2 upper(fmax(startPos.x, endPos.x), fmax(startPos.y, endPos.y));
		b2AABB aabb;
		aabb.lowerBound = lower;
		aabb.upperBound = upper;

		//Visualize the selection box
		Visualizer::AddAABB(aabb, Color::Type::Blue);

		PhysicsManager::GetWorld()->QueryAABB(pRayCast, aabb);
		pRayCast->ProcessList();

	}
}
