
// Andre Berthiaume, May 2017

#ifndef _TrailCollection
#define _TrailCollection

#include "ManagedPool.h"
#include "SceneLink.h"

class GameObject2D;

class TrailCollection : public ManagedPool
{
private:
	virtual GameObject2D* CreateNew() override;

public:

	TrailCollection();
	virtual ~TrailCollection();
	TrailCollection(const TrailCollection&) = delete;
	TrailCollection& operator=(const TrailCollection&) = delete;

	void Create(float pixx, float pixy, float ang);
	void DeleteTrail();

	void privAddToFront(SceneLink* node, SceneLink*& head);
	void privRemove(SceneLink* pNewData, SceneLink*& pHead);

	SceneLink* pLinks;
	// Note: missing stuff to add
	// - recall live feathers and 
	// - delete may leak if feathers sill active
};


#endif _TrailCollection
