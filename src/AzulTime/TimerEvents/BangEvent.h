#ifndef BANG_EVENT_H
#define BANG_EVENT_H

#include "GameObject2D.h"
#include "TimerEvent.h"
class BangEvent : public TimerEvent
{
public:

	BangEvent(GameObject2D* pNewObj);
	virtual void Execute(float currTime) override;
	virtual ~BangEvent();

private:
	GameObject2D* pObj;

};


#endif BANG_EVENT_H