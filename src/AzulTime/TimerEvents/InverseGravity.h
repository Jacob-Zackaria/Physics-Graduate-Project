#ifndef INVERSE_GRAVITY_H
#define INVERSE_GRAVITY_H

#include "GameObject2D.h"
#include "TimerEvent.h"
class InverseGravity : public TimerEvent
{
public:

	InverseGravity(GameObject2D* pNewObj);
	virtual void Execute(float currTime) override;
	virtual ~InverseGravity();

private:
	GameObject2D* pObj;
};


#endif INVERSE_GRAVITY_H