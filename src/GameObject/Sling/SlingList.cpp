#include "SlingList.h"

SlingList::SlingList(GameObject2D* pNewObj)
	:
	pLoadedBird(pNewObj),
	pNext(nullptr),
	pPrev(nullptr)
{
}

SlingList::~SlingList()
{
}

GameObject2D* SlingList::GetGameObject()
{
	return this->pLoadedBird;
}

//-----links----
void SlingList::setNext(SlingList* newNext)
{
	this->pNext = newNext;
}

void SlingList::setPrev(SlingList* newPrev)
{
	this->pPrev = newPrev;
}

SlingList* SlingList::getNext() const
{
	return (this->pNext);
}

SlingList* SlingList::getPrev() const
{
	return (this->pPrev);
}