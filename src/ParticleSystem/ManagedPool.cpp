#include "ManagedPool.h"
#include "GameObject2D.h"

ManagedPool::ManagedPool()
{

}

ManagedPool::~ManagedPool()
{
	// Delete recycled objects
	LinkNode* ptmp;
	while (!pRecycledPool.IsEmpty())
	{
		ptmp = pRecycledPool.Pop();
		delete ptmp->pEnt;		// Delete recycled GameObject2D
		delete ptmp;			// Delete LinkNode container

		//DebugMsg::out("Managed Pool: deleting (In reserve: %i)\n", pRecycledPool.Size());
	}

	while (!pEmptyContainers.IsEmpty())
	{
		ptmp = pEmptyContainers.Pop();
		delete ptmp;

		//DebugMsg::out("Managed Pool: deleting (In reserve: %i)\n", pEmptyContainers.Size());
	}

}

void ManagedPool::Recycle(GameObject2D* pEnt)
{
	LinkNode* plnk;
	
	// Get a storage container for the new object
	if ( pEmptyContainers.IsEmpty() )
	{
		plnk = new LinkNode();
	}
	else
	{
		plnk = pEmptyContainers.Pop();
	}

	// Store the object for later reuse
	plnk->pEnt = pEnt;
	pRecycledPool.push(plnk);
	//DebugMsg::out("Managed Pool: recycling (In reserve: %i)\n", pRecycledPool.Size() );
}

GameObject2D* ManagedPool::GetNew()
{
	GameObject2D* pNewEnt = nullptr;

	if ( pRecycledPool.IsEmpty() )
	{
		pNewEnt = CreateNew();
		//DebugMsg::out("Managed Pool: creating new (In reserve: %i)\n", pRecycledPool.Size() );
	}
	else
	{
		LinkNode* ptmp = pRecycledPool.Pop();
		pNewEnt = ptmp->pEnt;

		pEmptyContainers.push(ptmp);  // Save the container for later reuse

		//DebugMsg::out("Managed Pool: reusing (In reserve: %i)\n", pRecycledPool.Size() );
	}

	return pNewEnt;
}

void ManagedPool::EmptyRecycledPool()
{
	// Delete recycled objects
	LinkNode* ptmp;
	while (!pRecycledPool.IsEmpty())
	{
		ptmp = pRecycledPool.Pop();
		/*ptmp->pEnt = nullptr;*/
		delete ptmp;			// Delete LinkNode container

		//DebugMsg::out("Managed Pool: deleting (In reserve: %i)\n", pRecycledPool.Size());
	}
}

