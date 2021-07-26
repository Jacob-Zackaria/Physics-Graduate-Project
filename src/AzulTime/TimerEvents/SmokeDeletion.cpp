#include "SmokeDeletion.h"


SmokeDeletion::SmokeDeletion(GameObject2D* pNewObj)
	:
	pObj(pNewObj)
{
	this->SetName(TimerEvent::Name::SMOKE_DELETION);
}

void SmokeDeletion::Execute(float currTime)
{
	currTime;
	pObj->MarkForDelete();
}

SmokeDeletion::~SmokeDeletion()
{
}
