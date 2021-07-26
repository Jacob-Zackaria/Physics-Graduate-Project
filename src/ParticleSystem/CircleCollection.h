
// Andre Berthiaume, May 2017

#ifndef _CircleCollection
#define _CircleCollection

#include "ManagedPool.h"
#include "SceneLink.h"

class GameObject2D;

class CircleCollection : public ManagedPool
{
private:
	virtual GameObject2D* CreateNew() override;

public:

	CircleCollection();
	virtual ~CircleCollection();
	CircleCollection(const CircleCollection&) = delete;
	CircleCollection& operator=(const CircleCollection&) = delete;

	void Create(float pixx, float pixy, float ang);

	void privAddToFront(SceneLink* node, SceneLink*& head);
	void privRemove(SceneLink* pNewData, SceneLink*& pHead);

	SceneLink* pLinks;
	// Note: missing stuff to add
	// - recall live feathers and 
	// - delete may leak if feathers sill active
};


#endif _TrailCollection
