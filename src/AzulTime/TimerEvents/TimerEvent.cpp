#include "TimerEvent.h"

TimerEvent::TimerEvent()
	:
	TriggerTime(0.0f),
	name(TimerEvent::Name::NOT_INITIALIZED)
{
}

TimerEvent::~TimerEvent()
{
}


TimerEvent::Name TimerEvent::GetName() const
{
	return this->name;
}

void TimerEvent::SetName(TimerEvent::Name newName)
{
	this->name = newName;
}

void TimerEvent::SetTriggerTime(const float newTriggerTime)
{
	this->TriggerTime = newTriggerTime;
}

const float TimerEvent::GetTriggerTime() const
{
	return this->TriggerTime;
}
