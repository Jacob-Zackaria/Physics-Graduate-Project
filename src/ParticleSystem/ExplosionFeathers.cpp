#include "ExplosionFeathers.h"
#include "FeatherYellow.h"
#include "FeatherRed.h"
#include "FeatherBlack.h"
#include "FeatherBlue.h"
#include "FeatherGreen.h"
#include "FeatherWhite.h"
#include "GameObjectMan.h"

GameObject2D* ExplosionFeathers:: CreateNew()
{
	switch (this->featherType)
	{
		case FeatherType::YELLOW:
			return new FeatherYellow(this);
		case FeatherType::RED:
			return new FeatherRed(this);
		case FeatherType::BLACK:
			return new FeatherBlack(this);
		case FeatherType::BLUE:
			return new FeatherBlue(this);
		case FeatherType::GREEN:
			return new FeatherGreen(this);
		case FeatherType::WHITE:
			return new FeatherWhite(this);
		default:
			return nullptr;
	}
	
}


ExplosionFeathers::~ExplosionFeathers()
{
	//// delete from gameobject manager.
	//SceneLink* newGame = this->pLinks;
	//SceneLink* new2 = nullptr;
	//while (newGame != nullptr)
	//{
	//	new2 = newGame;
	//	newGame = newGame->getNext();
	//	this->privRemove(new2, this->pLinks);
	//	delete new2;
	//}

	//// remove from recycled pool.
	//this->EmptyRecycledPool();
}

void ExplosionFeathers::Create(FeatherType newFeather, float pixx, float pixy)
{
	this->featherType = newFeather;

	// should have a base class feather... works just for now
	FeatherYellow* p;
	FeatherRed* r;
	FeatherBlack* b;
	FeatherBlue* bl;
	FeatherGreen* g;
	FeatherWhite* w;
	//SceneLink* pNewLink = nullptr;
	switch (featherType)
	{
		case FeatherType::YELLOW:
			for (int i = 0; i < 5; i++)
			{
				p = (FeatherYellow*)this->GetNew();
				p->SetPosAng(pixx, pixy);

				GameObjectMan::Add(p, GameObjectName::Name::ObjectsBucket);

				/*pNewLink = new SceneLink(p);

				this->privAddToFront(pNewLink, this->pLinks);*/
			}
		break;
		case FeatherType::RED:
			for (int i = 0; i < 5; i++)
			{
				r = (FeatherRed*)this->GetNew();
				r->SetPosAng(pixx, pixy);

				GameObjectMan::Add(r, GameObjectName::Name::ObjectsBucket);

				/*pNewLink = new SceneLink(r);

				this->privAddToFront(pNewLink, this->pLinks);*/
			}
			break;
		case FeatherType::BLACK:
			for (int i = 0; i < 5; i++)
			{
				b = (FeatherBlack*)this->GetNew();
				b->SetPosAng(pixx, pixy);

				GameObjectMan::Add(b, GameObjectName::Name::ObjectsBucket);

				/*pNewLink = new SceneLink(b);

				this->privAddToFront(pNewLink, this->pLinks);*/
			}
			break;
		case FeatherType::BLUE:
			for (int i = 0; i < 5; i++)
			{
				bl = (FeatherBlue*)this->GetNew();
				bl->SetPosAng(pixx, pixy);

				GameObjectMan::Add(bl, GameObjectName::Name::ObjectsBucket);

				/*pNewLink = new SceneLink(bl);

				this->privAddToFront(pNewLink, this->pLinks);*/
			}
			break;
		case FeatherType::GREEN:
			for (int i = 0; i < 5; i++)
			{
				g = (FeatherGreen*)this->GetNew();
				g->SetPosAng(pixx, pixy);

				GameObjectMan::Add(g, GameObjectName::Name::ObjectsBucket);

				/*pNewLink = new SceneLink(g);

				this->privAddToFront(pNewLink, this->pLinks);*/
			}
			break;
		case FeatherType::WHITE:
			for (int i = 0; i < 5; i++)
			{
				w = (FeatherWhite*)this->GetNew();
				w->SetPosAng(pixx, pixy);

				GameObjectMan::Add(w, GameObjectName::Name::ObjectsBucket);

				/*pNewLink = new SceneLink(w);

				this->privAddToFront(pNewLink, this->pLinks);*/
			}
			break;
		default:
			break;

	}
	
}

//void ExplosionFeathers::privAddToFront(SceneLink* node, SceneLink*& head)
//{
//	assert(node);
//
//	if (head == nullptr)
//	{
//		head = node;
//		node->setNext(nullptr);
//		node->setPrev(nullptr);
//	}
//	else
//	{
//		node->setNext(head);
//		head->setPrev(node);
//		head = node;
//	}
//}
//
//void ExplosionFeathers::privRemove(SceneLink* pNewData, SceneLink*& pHead)
//{
//	//Check if node to delete has a next or prev links.
//	if (pNewData->getNext() == nullptr && pNewData->getPrev() == nullptr)
//	{
//		pHead = nullptr;
//	}
//	else if (pNewData->getPrev() == nullptr)    //Check if there is a prev link. 
//	{
//		pHead = pHead->getNext();
//		pHead->setPrev(nullptr);
//	}
//	else if (pNewData->getNext() == nullptr)    //Check if there is a next link.
//	{
//		pNewData->getPrev()->setNext(nullptr);
//	}
//	else                    //If no next or prev links are present.
//	{
//		pNewData->getPrev()->setNext(pNewData->getNext());
//		pNewData->getNext()->setPrev(pNewData->getPrev());
//	}
//
//	//Clear links of deleted node.
//	pNewData->setNext(nullptr);
//	pNewData->setPrev(nullptr);
//}
