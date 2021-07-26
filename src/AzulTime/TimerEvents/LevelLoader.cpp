#include "LevelLoader.h"
#include "NextLevelLoader.h"

LevelLoader::LevelLoader(Scene::Name newName)
	:
	pNewLink(nullptr),
	sceneName(newName)
{
}

void LevelLoader::Execute(float currTime)
{
	currTime;
	SceneLink* pLink = this->pNewLink;
	while (pLink != nullptr)
	{
		pLink->GetGameObject()->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		pLink = pLink->getNext();
	}

	// load next level
	TimerMan::AddEvent(2.0f, new NextLevelLoader(sceneName));
}

LevelLoader::~LevelLoader()
{
	SceneLink* pLink = this->pNewLink;
	SceneLink* temp = nullptr;
	while (pLink != nullptr)
	{
		pLink->SetNull();
		temp = pLink;
		pLink = pLink->getNext();
		delete temp;
	}
}

void LevelLoader::AddObjects(GameObject2D* newObj)
{
	SceneLink* pNewL = new SceneLink(newObj);

	this->privAddToFront(pNewL, this->pNewLink);
}

void LevelLoader::privAddToFront(SceneLink* node, SceneLink*& head)
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

void LevelLoader::privRemove(SceneLink* pNewData, SceneLink*& pHead)
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
