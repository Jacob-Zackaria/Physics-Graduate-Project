#include "InverseGravity.h"
#include "PhysicsManager.h"
#include "TimerMan.h"
#include "GravityBox.h"
InverseGravity::InverseGravity(GameObject2D* pNewObj)
	:
	pObj(pNewObj)
{
}

void InverseGravity::Execute(float currTime)
{
	currTime;

	PhysicsManager::GetWorld()->SetGravity(-1.0f * PhysicsManager::GetWorld()->GetGravity());

	TimerMan::AddEvent(6.0f, new GravityBox(pObj));
}

InverseGravity::~InverseGravity()
{
}
