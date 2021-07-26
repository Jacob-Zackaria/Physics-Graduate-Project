#include "GravityBox.h"
#include "TimerMan.h"
#include "InverseGravity.h"
#include "PhysicsManager.h"
GravityBox::GravityBox(GameObject2D* pNewObj)
	:
	pObj(pNewObj)
{
}

void GravityBox::Execute(float currTime)
{
	currTime;
	pObj->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, PhysicsManager::GetWorld()->GetGravity().y), true);

	TimerMan::AddEvent(3.0f, new InverseGravity(pObj));
}

GravityBox::~GravityBox()
{
}
