#include "BangEvent.h"


BangEvent::BangEvent(GameObject2D* pNewObj)
	:
	pObj(pNewObj)
{
	this->SetName(TimerEvent::Name::BANG);
}

void BangEvent::Execute(float currTime)
{
	currTime;
	pObj->MarkForDelete();
}

BangEvent::~BangEvent()
{
}
