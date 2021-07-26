#include "CircleCollection.h"
#include "CircleParticles.h"
#include "GameObjectMan.h"
#include "PhysicsManager.h"
GameObject2D* CircleCollection:: CreateNew()
{
	return new CircleParticles(this);
}


CircleCollection::CircleCollection()
	:
	pLinks(nullptr)
{
}

CircleCollection::~CircleCollection()
{
	SceneLink* newGame = this->pLinks;
	SceneLink* new2 = nullptr;
	while (newGame != nullptr)
	{
		new2 = newGame;
		newGame = newGame->getNext();
		this->privRemove(new2, this->pLinks);
		delete new2;
	}
}

void CircleCollection::Create(float pixx, float pixy, float ang)
{
	CircleParticles* p = (CircleParticles*)this->GetNew();

	PhysicsObject* pPhyObj = PhysicsManager::CreatePhysicsObject(p, b2BodyType::b2_dynamicBody);
	p->SetPhysicsObject(pPhyObj);

	p->SetPosAng(pixx, pixy, ang);
	p->setName("CircleParticles");
	GameObjectMan::Add(p, GameObjectName::Name::ObjectsBucket);

	SceneLink* pNewLink = new SceneLink(p);

	this->privAddToFront(pNewLink, this->pLinks);
}

void CircleCollection::privAddToFront(SceneLink* node, SceneLink*& head)
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

void CircleCollection::privRemove(SceneLink* pNewData, SceneLink*& pHead)
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
