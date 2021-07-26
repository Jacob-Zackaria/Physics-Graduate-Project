#include "SlingQueue.h"
#include "SlingFactory.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "BirdFactory.h"
#include "SlingDrag.h"
SlingQueue::SlingQueue()
	:
	sState(SlingState::EMPTY),
	pBirdList(nullptr),
	currentLoaded(nullptr),
	birdLimit(0),
	currentCount(0),
	slingPos(),
	trailCollection(nullptr)
{
}

SlingQueue* SlingQueue::privGetInstance()
{
	static SlingQueue instance;
	return &instance;
}

void SlingQueue::privAddToFront(SlingList* node, SlingList*& head)
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

void SlingQueue::privRemove(SlingList* pNewData, SlingList*& pHead)
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

SlingQueue::~SlingQueue()
{
}

void SlingQueue::Create(uint8_t newLimit, float newBaseX, float newBaseY)
{
	SlingQueue* pMan = SlingQueue::privGetInstance();

	// trail collection
	pMan->trailCollection = new TrailCollection();

	pMan->slingPos = b2Vec2(newBaseX - 20.0f, newBaseY + 50.0f);
	pMan->birdLimit = newLimit;
	pMan->currentCount = 0;
	pMan->sState = SlingQueue::SlingState::EMPTY;

	// SLING CREATION
	
	// slingStump1
	Rect rect = rect = Rect(newBaseX - 19.0f, newBaseY + 26.0f, 30.0f, 75.0f);
	GameObject2D* tC = SlingFactory::CreateObject(GameObjectName::Name::Sling_Stump1, rect, Rect());
	SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), tC);

	//Sling 1 right (big strip)
	rect = Rect(newBaseX - 10.0f, newBaseY + 44.0f, 40.0f, 10.0f);
	tC = SlingFactory::CreateObject(GameObjectName::Name::Sling2, rect, Rect());
	tC->SetCurrentAngle(0.1f);
	SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), tC);
	SlingDrag* pSystem = new SlingDrag(pMan->slingPos, 125.0f);
	pSystem->AddSling1(tC, b2Vec2(newBaseX + 10.0f, newBaseY + 45.0f), 75.0f);

	// Load Birds
	for (uint8_t i = SlingQueue::GetCurrentCount(); i < SlingQueue::GetBirdLimit(); i++)
	{
		// RedBird0
		rect = Rect((newBaseX - 70.0f) - (i * 40.0f), newBaseY - 50.0f, 50.0f, 50.0f);
		tC = BirdFactory::CreateBird(GameObjectName::Name::YellowBird0, rect, Rect(), true);
		SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), tC);
		SlingQueue::AddBird(tC);
	}

	// slingStump0
	rect = rect = Rect(newBaseX, newBaseY, 30.0f, 135.0f);
	tC = SlingFactory::CreateObject(GameObjectName::Name::Sling_Stump0, rect, Rect());
	SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), tC);
	//Sling 2 left (small strip)
	rect = Rect(newBaseX - 22.0f, newBaseY + 43.0f, 10.0f, 10.0f);
	tC = SlingFactory::CreateObject(GameObjectName::Name::Sling1, rect, Rect());
	SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), tC);
	pSystem->AddSling2(tC, b2Vec2(tC->GetPosX(), tC->GetPosY()), 75.0f);

	InputManager::AddInputs((InputSystem*)pSystem, InputSystem::InputType::SLING_DRAG);
}

void SlingQueue::Terminate()
{
	SlingQueue* pMan = SlingQueue::privGetInstance();

	SlingList* pTmp = pMan->pBirdList;
	SlingList* pTmp2 = nullptr;
	while (pTmp != nullptr)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->getNext();
		pMan->privRemove(pTmp2, pMan->pBirdList);
		delete pTmp2;
	}
	pMan->currentCount = 0;
	pMan->sState = SlingQueue::SlingState::EMPTY;

	InputManager::Delete(InputSystem::InputType::SLING_DRAG);

	delete pMan->trailCollection;
}

void SlingQueue::AddBird(GameObject2D* pBird)
{
	SlingQueue* pMan = SlingQueue::privGetInstance();

	if (pMan->currentCount < pMan->birdLimit)
	{
		pBird->GetBody()->SetActive(false);
		SlingList* pNewBird = new SlingList(pBird);
		pMan->privAddToFront(pNewBird, pMan->pBirdList);
		pMan->currentCount++;
	}
}

void SlingQueue::LoadNext()
{
	SlingQueue* pMan = SlingQueue::privGetInstance();

	SlingList* pTmp = nullptr;
	if (pMan->pBirdList != nullptr)
	{
		pTmp = pMan->pBirdList;
	}

	// remove from list
	pMan->privRemove(pTmp, pMan->pBirdList);
	pMan->currentCount--;
	pMan->sState = SlingQueue::SlingState::LOADED;

	pMan->currentLoaded = pTmp->GetGameObject();

	delete pTmp;

	pMan->currentLoaded->SetPos(pMan->slingPos.x, pMan->slingPos.y);
}

GameObject2D* SlingQueue::GetLoadedObject()
{
	return SlingQueue::privGetInstance()->currentLoaded;
}

const SlingQueue::SlingState SlingQueue::GetSlingState()
{
	return SlingQueue::privGetInstance()->sState;
}

uint8_t SlingQueue::GetCurrentCount()
{
	return SlingQueue::privGetInstance()->currentCount;
}

uint8_t SlingQueue::GetBirdLimit()
{
	return SlingQueue::privGetInstance()->birdLimit;
}

void SlingQueue::SetState(SlingState newState)
{
	SlingQueue::privGetInstance()->sState = newState;
}

bool SlingQueue::CheckExist(GameObject2D* newObj)
{
	SlingQueue* pMan = SlingQueue::privGetInstance();
	SlingList* pTmp = pMan->pBirdList;
	while (pTmp != nullptr)
	{
		if (&*pTmp->GetGameObject() == &*newObj)
		{
			return true;
		}
		pTmp = pTmp->getNext();
	}

	return false;
}

void SlingQueue::ReloadBirds(float newBaseX, float newBaseY)
{
	// Load Birds
	for (uint8_t i = SlingQueue::GetCurrentCount(); i < SlingQueue::GetBirdLimit(); i++)
	{
		// RedBird0
		Rect rect = Rect((newBaseX - 70.0f) - (i * 40.0f), newBaseY - 50.0f, 50.0f, 50.0f);
		GameObject2D* tC = BirdFactory::CreateBird(GameObjectName::Name::YellowBird0, rect, Rect(), true);
		SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), tC);
		SlingQueue::AddBird(tC);
	}
}

TrailCollection* SlingQueue::GetTrailCollection()
{
	return SlingQueue::privGetInstance()->trailCollection;
}
