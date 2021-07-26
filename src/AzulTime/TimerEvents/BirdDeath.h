#ifndef BIRD_DEATH_H
#define BIRD_DEATH_H

#include "GameObject2D.h"
#include "TimerEvent.h"
class BirdDeath : public TimerEvent
{
public:

	BirdDeath(GameObject2D* pNewObj);
	virtual void Execute(float currTime) override;
	virtual ~BirdDeath();

private:
	GameObject2D* pObj;

};


#endif BIRD_DEATH_H