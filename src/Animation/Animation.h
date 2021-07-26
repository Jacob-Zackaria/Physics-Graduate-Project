#ifndef ANIMATION_H
#define ANIMATION_H

#include "ImageNameLink.h"

class Animation 
{
	
public:
	Animation();
	Animation(const Animation&) = delete;
	const Animation& operator = (const Animation&) = delete;
	~Animation();

	void Add(const ImageName::Name newName, const float newHealthVal, const Rect newRect);
	GraphicsObject_Sprite* GetSprite();
	const float GetHealthVal() const;
	const ImageNameLink* GetLink();
	void SetNextLink();

	//-----links----
	void setNext(Animation* newNext);
	void setPrev(Animation* newPrev);
	Animation* getNext() const;
	Animation* getPrev() const;
private:
	void privAddToEnd(ImageNameLink* node, ImageNameLink*& head);
	void privRemove(ImageNameLink* pNewData, ImageNameLink*& pHead);

	ImageNameLink* pList;

	// links
	Animation* pNext;
	Animation* pPrev;
};


#endif ANIMATION_H