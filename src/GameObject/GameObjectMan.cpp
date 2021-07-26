#include <assert.h>

#include "GameObject2D.h"
#include "GameObjectMan.h"


void GameObjectMan::Add(GameObject *pObj, GameSortBucket *pGameSort)
{
	assert(pObj != 0);
	assert(pGameSort != 0);

	// Get singleton
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();

	// insert object to root
	pGOM->pRootTree->insert(pObj, pGameSort);
}

void GameObjectMan::Create()
{
	GameObjectMan* pGOM = GameObjectMan::privGetInstance();
	pGOM;
}

void GameObjectMan::Add(GameSortBucket *pGameSort)
{
	assert(pGameSort != 0);

	// Get singleton
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();

	// Get root node
	PCSNode *pRootNode = pGOM->pRootTree->getRoot();

	// insert object to root
	pGOM->pRootTree->insert(pGameSort, pRootNode);
}

void GameObjectMan::Add(GameObject *pObj, GameObjectName::Name SortName)
{
	GameSortBucket* pSortbucket = (GameSortBucket*)Find(SortName);
	assert(pSortbucket);

	Add(pObj, pSortbucket);
}

void  GameObjectMan::AddToDeleteList(GameObject *pObj)
{
	assert(pObj != 0);
	// Get singleton
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();

	GameObjectDeleteLink *pDel = new GameObjectDeleteLink(pObj);

	// Add to front
	pDel->next = pGOM->pDeleteLink;
	pGOM->pDeleteLink = pDel;
}

void GameObjectMan::DeleteSortBucket(GameSortBucket* pSortBucket)
{
	// Get singleton
	GameObjectMan* pGOM = GameObjectMan::privGetInstance();

	PCSNode* pChild = pSortBucket->getChild();
	PCSNode* pNewChild2 = nullptr;
	while (pChild != nullptr)
	{
		pNewChild2 = pChild;
		pChild = pChild->getSibling();
		pGOM->Delete((GameObject*)pNewChild2);
	}
}

void GameObjectMan::Delete(GameObject *pObj)
{
	assert(pObj);
	// Get singleton
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();

	pObj->deleteMe = true;
	pGOM->pRootTree->remove(pObj);

	// delete this node game object
	delete pObj;
}

GameObject *GameObjectMan::Find(GameObjectName::Name name)
{
	// Get singleton
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();
	assert(pGOM);

	GameObject *pObj = 0;
	pGOM->privFind(&pObj, pGOM, pGOM->pRootTree->getRoot(), name);

	return pObj;
}

void GameObjectMan::privFind(GameObject **pObj, GameObjectMan *pGOM, PCSNode *pNode, GameObjectName::Name name)
{
	// Update the game object
	GameObject *pGameObj = (GameObject2D *)pNode;


	if ((unsigned int)pGameObj->getName() == (unsigned int)name)
	{
		*pObj = pGameObj;
	}

	{
		// iterate through all of the active children 
		if (pNode->getChild() != 0)
		{
			PCSNode *pChild = pNode->getChild();
			// make sure that allocation is not a child node 
			while (pChild != 0)
			{
				pGOM->privFind(pObj, pGOM, pChild, name);
				// goto next sibling
				pChild = pChild->getSibling();
			}
		}
		else
		{
			// bye bye exit condition
		}
	}
}

void  GameObjectMan::DeletePending()
{
	// Get singleton
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();

	GameObjectDeleteLink *pDel = pGOM->pDeleteLink;
	while (pDel)
	{
		GameObjectDeleteLink *ptmp = pDel->next;

		pGOM->pRootTree->remove(pDel->p);

		// delete this node game object
		if (!(pDel->p->ManagedNoDelete))
		{
			delete pDel->p;
		}
		else
		{
			pDel->p->deleteMe = false;		// Restore the delete flag
			pDel->p->ManagedSceneExit();	// Process exit operations
		}

		// detete the container for the delete list
		delete pDel;

		pGOM->pDeleteLink = ptmp;

		pDel = ptmp;
	}
}

void GameObjectMan::Update(float currentTime)
{
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();
	assert(pGOM);

	PCSNode *pRootNode = pGOM->pRootTree->getRoot();
	assert(pRootNode);

	// update
	pGOM->privUpdate(pGOM, pRootNode, currentTime);

	// Do the delete list
	GameObjectMan::DeletePending();
}

void GameObjectMan::privUpdate(GameObjectMan *pGOM, PCSNode *pNode, float currentTime)
{
	// Update the game object
	GameObject *pGameObj = (GameObject *)pNode;
	pGameObj->Update(currentTime);

	// iterate through all of the active children 
	if (pNode->getChild() != 0)
	{
		PCSNode *pChild = pNode->getChild();
		// make sure that allocation is not a child node 
		while (pChild != 0)
		{
			pGOM->privUpdate(pGOM, pChild, currentTime);
			// goto next sibling
			pChild = pChild->getSibling();
		}
	}
	else
	{
		// bye bye exit condition
	}
}

void GameObjectMan::Draw()
{
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();
	assert(pGOM);

	PCSNode *pRootNode = pGOM->pRootTree->getRoot();
	assert(pRootNode);

	// Draw eveything in depth first order
	pGOM->privDraw(pGOM, pRootNode);
}

void GameObjectMan::privDraw(GameObjectMan *pGOM, PCSNode *pNode)
{
	// draw sprite & debug volumes
	((GameObject2D *)pNode)->Draw();

	// iterate through all of the active children 
	if (pNode->getChild() != 0)
	{
		PCSNode *pChild = pNode->getChild();
		// make sure that allocation is not a child node 
		while (pChild != 0)
		{
			pGOM->privDraw(pGOM, pChild);
			// goto next sibling
			pChild = pChild->getSibling();
		}
	}
	else
	{
		// bye bye exit condition
	}
}

GameObjectMan::GameObjectMan()
	:
	pDeleteLink(nullptr)
{
	this->pRootTree = new PCSTree();
	assert(this->pRootTree);

	//PCSNode *pRootNode = new PCSNode("GameObject_Root");
	PCSNode *pRootNode = new GameObject2D(GameObjectName::Name::Root);
	assert(pRootNode);

	// Set it to be root
	pRootTree->insert(pRootNode, 0);
}


GameObjectMan * GameObjectMan::privGetInstance(void)
{
	// This is where its actually stored (BSS section)
	static GameObjectMan gom;

	return &gom;
}

void GameObjectMan::Terminate()
{
	GameObjectMan *pGOM = GameObjectMan::privGetInstance();
	assert(pGOM);

	// Update the game object
	PCSNode* pGameObj = pGOM->pRootTree->getRoot();


	// iterate through all of the active children 
	if (pGameObj->getChild() != nullptr)
	{
		PCSNode* pChild = pGameObj->getChild();
		PCSNode* pNewChild2 = nullptr;
		// make sure that allocation is not a child node 
		while (pChild != nullptr)
		{
			PCSNode* pNewChild = pChild->getChild();
			while (pNewChild != nullptr)
			{
				pNewChild2 = pNewChild;
				pNewChild = pNewChild->getSibling();
				pGOM->Delete((GameObject*)pNewChild2);
			}

			pNewChild2 = pChild;
			pChild = pChild->getSibling();
			pGOM->Delete((GameObject*)pNewChild2);
		}
	}
	

	GameObject* ptmp = (GameObject*)pGameObj;
	pGOM->pRootTree->remove(ptmp);
	delete ptmp;

	delete pGOM->pRootTree;
}

