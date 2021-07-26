#ifndef TIMER_EVENT_H
#define TIMER_EVENT_H

class TimerLink
{
public:
	TimerLink()
		:next(0), prev(0)
	{

	}

	TimerLink *next;
	TimerLink *prev;
};


class TimerEvent : public TimerLink
{
public:
	enum class Name
	{
		BANG,
		SMOKE_DELETION,
		NOT_INITIALIZED
	};
	TimerEvent();
	virtual void Execute(float currTime) = 0;
	virtual ~TimerEvent();

	Name GetName() const;
	void SetName(Name newName);
	void SetTriggerTime(const float newTriggerTime);
	const float GetTriggerTime() const;

private:
	Name name;
	float TriggerTime;
};


#endif