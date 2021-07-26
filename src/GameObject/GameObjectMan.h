#ifndef GAME_OBJECT_MAN_H
#define GAME_OBJECT_MAN_H

#include "GameObject.h"
#include "PCSTree.h"
#include "GameSortBucket.h"

class GameObjectDeleteLink
{
public:
	GameObjectDeleteLink(GameObject *pObj)
		:p(pObj), next(0)
	{

	}

	GameObjectDeleteLink *next;
	GameObject *p;
};


// Singleton
class GameObjectMan
{
public:
	
	static void Create();
	static void Add(GameSortBucket *pGameSort);
	static void Add(GameObject *pObj, GameSortBucket *pGameSort);
	static void Add(GameObject *pObj, GameObjectName::Name SortName);
	static void Draw( void );
	static void Update( float currentTime );

	static void AddToDeleteList(GameObject *pObj);
	static void DeletePending();

	static void DeleteSortBucket(GameSortBucket* pSortBucket);
	static void Delete(GameObject *pObj);
	static GameObject* Find(GameObjectName::Name name);

	static void Terminate();

private:
	GameObjectMan();
	static GameObjectMan *privGetInstance();
	PCSTree *pRootTree;

	void privUpdate(GameObjectMan *pGOM, PCSNode *pNode, float currentTime);
	void privDraw(GameObjectMan *pGOM, PCSNode *pNode);

	void privFind(GameObject **pObj, GameObjectMan *pGOM, PCSNode *pNode, GameObjectName::Name name);

	GameObjectDeleteLink *pDeleteLink;

};

#endif