#ifndef TEST_LINK_H
#define TEST_LINK_H

#include "GameObject2D.h"

struct TestLink
{
	enum class BirdState
	{
		NORMAL,
		DRAGGED,
		IMPULSE
	};


	TestLink(GameObject2D* pNewObj)
		:
		pObj(pNewObj),
		bodyState(BirdState::NORMAL),
		pNext(nullptr),
		pPrev(nullptr)
	{}
	~TestLink()
	{
	}

	GameObject2D* GetGameObject()
	{
		return (this->pObj);
	}

	//-----links----
	void TestLink::setNext(TestLink* newNext)
	{
		this->pNext = newNext;
	}

	void TestLink::setPrev(TestLink* newPrev)
	{
		this->pPrev = newPrev;
	}

	TestLink* TestLink::getNext() const
	{
		return (this->pNext);
	}

	TestLink* TestLink::getPrev() const
	{
		return (this->pPrev);
	}

	// public data
	BirdState bodyState;
private:
	
	GameObject2D* pObj;
	

	TestLink* pNext;
	TestLink* pPrev;

};


#endif TEST_LINK_H