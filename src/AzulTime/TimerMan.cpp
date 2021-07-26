#include <assert.h>
#include "TimerMan.h"
#include "Game.h"

// NB: this is a functional time event manager, but it
// woudl be more efficient to keep the events 
// ordered by trigger time. Future version.
// NB: coudl also use a bit more safeties...

TimerMan* TimerMan::ptrInstance = nullptr;

TimerMan::TimerMan()
{
	pHead = nullptr;
	currTime = Game::GetTotalTime();
}

TimerMan::~TimerMan()
{
	
}

void TimerMan::AddEvent(float TimeInSec, TimerEvent *pEvent)
{
	pEvent->SetTriggerTime(Instance().currTime + TimeInSec);

	Instance().privAddToFront(pEvent);
}

void TimerMan::RemoveEvent(TimerEvent *pEvent)
{
	Instance().privRemoveFromList(pEvent);
}

void TimerMan::privRemoveFromList(TimerEvent *pEvent)
{
	// NB: This assumes pEvent legitimately came from the event list

	if (pEvent->prev == nullptr && pEvent->next == nullptr)
	{   // only one item in list
		this->pHead = nullptr;
	}
	else if (pEvent->prev == nullptr && pEvent->next != nullptr)
	{   // first on list
		this->pHead = (TimerEvent *)pEvent->next;
		this->pHead->prev = nullptr;
	}
	else if (pEvent->prev != nullptr && pEvent->next == nullptr)
	{    // last on list
		pEvent->prev->next = nullptr;
	}
	else
	{	// middle of list
		pEvent->prev->next = pEvent->next;
		pEvent->next->prev = pEvent->prev;
	}

	//delete pEvent;  // No! We do not own these events!
}

void TimerMan::privAddToFront(TimerEvent *pEvent)
{
	//  Adding in order of trigger time would be better...
	if (pHead == nullptr)
	{
		pHead = pEvent;
		pEvent->next = nullptr;
		pEvent->prev = nullptr;
	}
	else
	{
		pEvent->next = pHead;
		pEvent->prev = nullptr;
		pHead->prev = pEvent;
		pHead = pEvent;
	}
}

void TimerMan::Update()
{
	Instance().currTime = Game::GetTotalTime();

	TimerEvent *pEvent = Instance().pHead;
	while (pEvent != nullptr)
	{
		TimerEvent *pEvent_next = (TimerEvent *)pEvent->next;
		TimerEvent* pTmp2 = nullptr;
		if (Instance().currTime >= pEvent->GetTriggerTime())
		{
			pTmp2 = pEvent;
			RemoveEvent(pEvent);
			pEvent->Execute(Instance().currTime);
			pEvent = pEvent_next;
			delete pTmp2; // bad method, need to fix
		}
		else
		{
			pEvent = pEvent_next;
		}
	}

}

void TimerMan::Terminate()
{
	Instance().ClearTimerEvents();

	delete Instance().ptrInstance;
}

void TimerMan::ClearTimerEvents()
{
	TimerEvent* pTmp = Instance().pHead;
	TimerEvent* pTmp2 = nullptr;
	while (pTmp != nullptr)
	{
		pTmp2 = pTmp;
		pTmp = (TimerEvent*)pTmp->next;
		RemoveEvent(pTmp2);
		delete pTmp2;
	}
}
