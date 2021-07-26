
// Andre Berthiaume, May 2017

#ifndef _ProjectorCollection
#define _ProjectorCollection

#include "ManagedPool.h"
#include "SceneLink.h"

class GameObject2D;

class ProjectorCollection : public ManagedPool
{
private:
	virtual GameObject2D* CreateNew() override;

public:

	ProjectorCollection();
	virtual ~ProjectorCollection();
	ProjectorCollection(const ProjectorCollection&) = delete;
	ProjectorCollection& operator=(const ProjectorCollection&) = delete;

	void Create(float pixx, float pixy, float ang);
	void DeleteProjection();

	void privAddToFront(SceneLink* node, SceneLink*& head);
	void privRemove(SceneLink* pNewData, SceneLink*& pHead);

	SceneLink* pLinks;
	// Note: missing stuff to add
	// - recall live feathers and 
	// - delete may leak if feathers sill active
};


#endif ProjectorCollection
