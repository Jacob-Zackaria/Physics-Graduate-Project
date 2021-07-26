#ifndef TRAIL_CREATION_H
#define TRAIL_CREATION_H

#include "Bird.h"
#include "TimerEvent.h"
#include "TrailCollection.h"
class TrailCreation : public TimerEvent
{
public:

	TrailCreation(Bird* pNewObj, TrailCollection* newTrailCollection);
	virtual void Execute(float currTime) override;
	virtual ~TrailCreation();

private:
	Bird* pObj;
	TrailCollection* trailCollection;
};


#endif BIRD_DEATH_H