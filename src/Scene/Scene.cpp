 #include "Scene.h"
#include "SlingQueue.h"
Scene::Scene()
	:
	pName(Scene::Name::NOT_INITIALIZED),
	gameObj(nullptr),
	pNext(nullptr),
	pPrev(nullptr)
{
}

Scene::~Scene()
{
	
}


Scene::Name Scene::GetName()
{
	return this->pName;
}

void Scene::SetName(Scene::Name newName)
{
	this->pName = newName;
}

void Scene::Add(GameObject2D* newObj)
{
	SceneLink* newGameObj = new SceneLink(newObj);

	this->privAddToFront(newGameObj, this->gameObj);
}

void Scene::DeleteSceneElements()
{
	this->Clean();

	SceneLink* newGame = this->gameObj;
	SceneLink* new2 = nullptr;
	while (newGame != nullptr)
	{
		new2 = newGame;
		newGame = newGame->getNext();
		this->privRemove(new2, this->gameObj);
		delete new2;

	}
}

void Scene::Delete(GameObject2D* newObj)
{
	SceneLink* newGame = this->gameObj;
	SceneLink* new2 = nullptr;
	while (newGame != nullptr)
	{
		// need to fix, add game object ID to gameobjects
		if (&*newGame->GetGameObject() == &*newObj)
		{
			new2 = newGame;
			newGame = newGame->getNext();
			this->privRemove(new2, this->gameObj);
			new2->Delete();
			delete new2;
			break;
		}
		else
		{
			newGame = newGame->getNext();
		}
	}
}


//-----links----
void Scene::setNext(Scene* newNext)
{
	this->pNext = newNext;
}

void Scene::setPrev(Scene* newPrev)
{
	this->pPrev = newPrev;
}

Scene* Scene::getNext() const
{
	return (this->pNext);
}

Scene* Scene::getPrev() const
{
	return (this->pPrev);
}

void Scene::privAddToFront(SceneLink* node, SceneLink*& head)
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

void Scene::privRemove(SceneLink* pNewData, SceneLink*& pHead)
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
