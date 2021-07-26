#include "TrailCreation.h"
#include "PixelToMeter.h"
#include "TimerMan.h"
TrailCreation::TrailCreation(Bird* pNewObj, TrailCollection* newTrailCollection)
	:
	pObj(pNewObj),
	trailCollection(newTrailCollection)
{
}

void TrailCreation::Execute(float currTime)
{
	currTime;

	b2Vec2 pos = pObj->GetBody()->GetPosition();
	this->trailCollection->Create(MeterToPixel(pos.x), MeterToPixel(pos.y), pObj->GetBody()->GetAngle());

	if (pObj->bState == Bird::BirdState::FLYING)
	{
		TimerMan::AddEvent(0.03f, new TrailCreation(pObj, this->trailCollection));
	}
}

TrailCreation::~TrailCreation()
{

}
