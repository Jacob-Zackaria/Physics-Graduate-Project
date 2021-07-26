#include "Animation.h"

Animation::Animation()
	:
	pList(nullptr),
	pNext(nullptr),
	pPrev(nullptr)
{
	
}

Animation::~Animation()
{
	ImageNameLink* pTmp = this->pList;
	ImageNameLink* pTmp2 = nullptr;
	while (pTmp != nullptr)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->getNext();
		delete pTmp2->GetSprite();
		delete pTmp2;
	}

}

void Animation::Add(const ImageName::Name newName, const float newHealthVal, const Rect newRect)
{
	ImageNameLink* newLink = new ImageNameLink(newName, newHealthVal, newRect);

	this->privAddToEnd(newLink, this->pList);
}

GraphicsObject_Sprite* Animation::GetSprite()
{
	return this->pList->GetSprite();
}

const float Animation::GetHealthVal() const
{
	return this->pList->GetVal();
}

const ImageNameLink* Animation::GetLink()
{
	return this->pList;
}

void Animation::SetNextLink()
{
	ImageNameLink* plink = this->pList;

	this->privRemove(plink, this->pList);

	delete plink;
}


//-----links----
void Animation::setNext(Animation* newNext)
{
	this->pNext = newNext;
}

void Animation::setPrev(Animation* newPrev)
{
	this->pPrev = newPrev;
}

Animation* Animation::getNext() const
{
	return (this->pNext);
}

Animation* Animation::getPrev() const
{
	return (this->pPrev);
}


void Animation::privAddToEnd(ImageNameLink* node, ImageNameLink*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setPrev(nullptr);
	}
	else
	{
		ImageNameLink* pTmp = head;
		while (pTmp->getNext() != nullptr)
		{
			pTmp = pTmp->getNext();
		}
		node->setPrev(pTmp);
		pTmp->setNext(node);
	}
	node->setNext(nullptr);
}

void Animation::privRemove(ImageNameLink* pNewData, ImageNameLink*& pHead)
{
	//Check if node to delete has a next or prev links.
	if (pNewData->getNext() == nullptr && pNewData->getPrev() == nullptr)
	{
		pHead = nullptr;
	}
	else if (pNewData->getPrev() == nullptr)    //Check if there is a prev link. 
	{
		pHead = pHead->getNext();
		pHead->setPrev(nullptr);
	}
	else if (pNewData->getNext() == nullptr)    //Check if there is a next link.
	{
		pNewData->getPrev()->setNext(nullptr);
	}
	else                    //If no next or prev links are present.
	{
		pNewData->getPrev()->setNext(pNewData->getNext());
		pNewData->getNext()->setPrev(pNewData->getPrev());
	}

	//Clear links of deleted node.
	pNewData->setNext(nullptr);
	pNewData->setPrev(nullptr);
}
