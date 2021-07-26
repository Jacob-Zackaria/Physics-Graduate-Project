#ifndef SMOKE_DELETION_H
#define SMOKE_DELETION_H

#include "GameObject2D.h"
#include "TimerEvent.h"
class SmokeDeletion : public TimerEvent
{
public:

	SmokeDeletion(GameObject2D* pNewObj);
	virtual void Execute(float currTime) override;
	virtual ~SmokeDeletion();

private:
	GameObject2D* pObj;

};


#endif SMOKE_DELETION_H