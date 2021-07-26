#include "ABStack.h"
#include <assert.h>

ABStack::ABStack()
{
	this->pHead = nullptr;
	this->count = 0;
}

void ABStack::push(LinkNode* pEnt)
{
	assert(pEnt != nullptr);

	pEnt->pNext = pHead;
	this->pHead = pEnt;
	this->count++;
}

LinkNode* ABStack::Pop()
{
	assert(this->pHead != nullptr);

	LinkNode* ptmp = this->pHead;
	pHead = this->pHead->pNext;
	this->count--;

	return ptmp;
}

ABStack::~ABStack()
{
	while (this->pHead != nullptr)
	{
		LinkNode* ptmp = pHead;
		this->pHead = pHead->pNext;
		
		delete ptmp;
		this->count--;
	}

	assert(count == 0);
}