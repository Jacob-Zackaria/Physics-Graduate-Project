#include "RayCastQuery.h"
#include "InputManager.h"
#include "Visualizer.h"
#include "PhysicsManager.h"
RayCastQuery::RayCastQuery()
	:
	pRayCast(new LineRayCast())
{
}

RayCastQuery::~RayCastQuery()
{
	delete pRayCast;
}

void RayCastQuery::Update()
{
	static bool LeftButtonDown = false;
	static b2Vec2 prevPos;

	if ((InputManager::GetMouseState() == InputManager::MouseState::LEFT) && !LeftButtonDown)
	{
		// begin capture
		prevPos = InputManager::GetMouseWorld();		// Start of the line
		//DebugMsg::out("Line: Begin\n");
		LeftButtonDown = true;
	}
	else if ((InputManager::GetMouseState() == InputManager::MouseState::LEFT) && LeftButtonDown)
	{
		// continue capture
		b2Vec2 WorldMousePos = InputManager::GetMouseWorld(); // End of the line

												// If mouse has actually moved
		if ((WorldMousePos - prevPos).LengthSquared() > .01f)
		{
			// Debug view
			Visualizer::AddLineWorld(prevPos, WorldMousePos);

			// Query the line
			PhysicsManager::GetWorld()->RayCast(pRayCast, prevPos, WorldMousePos);
			pRayCast->ProcessList();

			//DebugMsg::out("Line: (%.2f, %.2f) - (%.2f, %.2f)\n", prevPos.x, prevPos.y, WorldMousePos.x, WorldMousePos.y);
			LeftButtonDown = true;
			prevPos = WorldMousePos; // next line's start point
		}

	}
	else if (!(InputManager::GetMouseState() == InputManager::MouseState::LEFT) && LeftButtonDown)
	{
		// end capture
		pRayCast->ClearList();

		//DebugMsg::out("Line: End\n");
		LeftButtonDown = false;

		// Debug view
		Visualizer::ClearLines();
	}
}
