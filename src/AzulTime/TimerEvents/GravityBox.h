#ifndef GRAVITY_BOX_H
#define GRAVITY_BOX_H

#include "GameObject2D.h"
#include "TimerEvent.h"
class GravityBox : public TimerEvent
{
public:

	GravityBox(GameObject2D* pNewObj);
	virtual void Execute(float currTime) override;
	virtual ~GravityBox();

private:
	GameObject2D* pObj;

};


#endif GRAVITY_BOX_H