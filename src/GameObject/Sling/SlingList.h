#ifndef SLING_LIST_H
#define SLING_LIST_H

#include "GameObject2D.h"
class SlingList
{
public:

	SlingList(GameObject2D* pNewObj);
	SlingList(const SlingList&) = delete;
	const SlingList& operator = (const SlingList&) = delete;
	~SlingList();

	GameObject2D* GetGameObject();

	//-----links----
	void setNext(SlingList* newNext);
	void setPrev(SlingList* newPrev);
	SlingList* getNext() const;
	SlingList* getPrev() const;
private:
	GameObject2D* pLoadedBird;

	// links
	SlingList* pNext;
	SlingList* pPrev;
};

#endif SLING_QUEUE_H