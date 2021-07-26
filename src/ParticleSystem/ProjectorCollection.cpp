#include "ProjectorCollection.h"
#include "Projector.h"
#include "GameObjectMan.h"

GameObject2D* ProjectorCollection:: CreateNew()
{
	return new Projector(this);
}


ProjectorCollection::ProjectorCollection()
	:
	pLinks(nullptr)
{
}

ProjectorCollection::~ProjectorCollection()
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

void ProjectorCollection::Create(float pixx, float pixy, float ang)
{
	Projector* p = (Projector*)this->GetNew();

	p->SetPosAng(pixx, pixy, ang);
	p->setName("Projector");
	GameObjectMan::Add(p, GameObjectName::Name::ObjectsBucket);

	SceneLink* pNewLink = new SceneLink(p);

	this->privAddToFront(pNewLink, this->pLinks);
}

void ProjectorCollection::DeleteProjection()
{
	SceneLink* newGame = this->pLinks;
	SceneLink* new2 = nullptr;
	while (newGame != nullptr)
	{
		new2 = newGame;
		newGame = newGame->getNext();
		this->privRemove(new2, this->pLinks);
		new2->Delete();
		delete new2;
	}
}

void ProjectorCollection::privAddToFront(SceneLink* node, SceneLink*& head)
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

void ProjectorCollection::privRemove(SceneLink* pNewData, SceneLink*& pHead)
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
