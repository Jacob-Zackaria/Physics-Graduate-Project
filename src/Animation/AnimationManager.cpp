#include "AnimationManager.h"

AnimationManager::AnimationManager()
	:
	pList(nullptr)
{
}

AnimationManager* AnimationManager::privGetInstance()
{
	static AnimationManager instance;
	return &instance;
}

void AnimationManager::privAddToFront(Animation* node, Animation*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setNext(nullptr);
		node->setPrev(nullptr);
	}
	else
	{
		node->setNext(head);
		head->setPrev(node);
		head = node;
	}
}

void AnimationManager::privRemove(Animation* pNewData, Animation*& pHead)
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

AnimationManager::~AnimationManager()
{
}

void AnimationManager::Add(Animation* pNewAnim, Animation::Name newName)
{
	AnimationManager* pMan = AnimationManager::privGetInstance();

	pNewAnim->SetName(newName);

	pMan->privAddToFront(pNewAnim, pMan->pList);
}

Animation* AnimationManager::Find(const Animation::Name newName)
{
	AnimationManager* pMan = AnimationManager::privGetInstance();

	Animation* pAnim = pMan->pList;
	while (pAnim != nullptr)
	{
		if (pAnim->GetName() == newName)
		{
			return pAnim;
		}
		pAnim = pAnim->getNext();
	}

	return nullptr;
}

void AnimationManager::Terminate()
{
	AnimationManager* pMan = AnimationManager::privGetInstance();

	Animation* temp = pMan->pList;
	Animation* temp2;
	while (temp != nullptr)
	{
		temp2 = temp;
		temp = temp->getNext();
		delete temp2;
	}
}
