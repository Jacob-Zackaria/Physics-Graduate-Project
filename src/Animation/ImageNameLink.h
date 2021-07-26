#ifndef IMAGE_NAME_LINK_H
#define IMAGE_NAME_LINK_H

#include "ImageName.h"
#include "GraphicsObject_Sprite.h"
class ImageNameLink
{
public:

	ImageNameLink(ImageName::Name newName, const float newHealthVal, Rect newRect)
		:
		healthVal(newHealthVal),
		pNext(nullptr),
		pPrev(nullptr)
	{
		this->pSprite = new GraphicsObject_Sprite(newName, newRect);
	}
	ImageNameLink(const ImageNameLink&) = delete;
	const ImageNameLink& operator = (const ImageNameLink&) = delete;
	~ImageNameLink()
	{
	}

	GraphicsObject_Sprite* GetSprite() const
	{
		return this->pSprite;
	}

	const float GetVal() const
	{
		return this->healthVal;
	}

	//-----links----
	void ImageNameLink::setNext(ImageNameLink* newNext)
	{
		this->pNext = newNext;
	}

	void ImageNameLink::setPrev(ImageNameLink* newPrev)
	{
		this->pPrev = newPrev;
	}

	ImageNameLink* ImageNameLink::getNext() const
	{
		return (this->pNext);
	}

	ImageNameLink* ImageNameLink::getPrev() const
	{
		return (this->pPrev);
	}

private:
	float healthVal;
	GraphicsObject_Sprite* pSprite;

	// links
	ImageNameLink* pNext;
	ImageNameLink* pPrev;
};

#endif IMAGE_NAME_LINK_H