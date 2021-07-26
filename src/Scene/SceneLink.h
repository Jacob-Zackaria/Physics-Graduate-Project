#ifndef SCENE_LINK_H
#define SCENE_LINK_H

#include "GameObjectMan.h"
class SceneLink
{
public:

	SceneLink(GameObject2D* pObj)
		:
		pNext(nullptr),
		pPrev(nullptr)
	{
		this->gameObj = pObj;
	}
	SceneLink(const SceneLink&) = delete;
	const SceneLink& operator = (const SceneLink&) = delete;
	~SceneLink()
	{
		if (this->gameObj != nullptr)
		{
			GameObjectMan::Delete(this->gameObj);
		}
	}

	GameObject2D* GetGameObject()
	{
		return this->gameObj;
	}

	void SetNull()
	{
		this->gameObj = nullptr;
	}

	void Delete()
	{
		this->gameObj->MarkForDelete();
		this->gameObj = nullptr;
	}

	//-----links----
	void SceneLink::setNext(SceneLink* newNext)
	{
		this->pNext = newNext;
	}

	void SceneLink::setPrev(SceneLink* newPrev)
	{
		this->pPrev = newPrev;
	}

	SceneLink* SceneLink::getNext() const
	{
		return (this->pNext);
	}

	SceneLink* SceneLink::getPrev() const
	{
		return (this->pPrev);
	}

private:
	GameObject2D* gameObj;

	// links
	SceneLink* pNext;
	SceneLink* pPrev;
};

#endif SCENE_LINK_H