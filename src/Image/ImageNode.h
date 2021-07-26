#ifndef IMAGE_NODE_H
#define IMAGE_NODE_H

#include "Image.h"

class ImageNodeLink
{
public:
	ImageNodeLink()
	{
		this->next = 0;
		this->prev = 0;
	}
	~ImageNodeLink()
	{
	}
	ImageNodeLink *next;
	ImageNodeLink *prev;
};


class ImageNode : public ImageNodeLink
{
public:
	ImageNode();
	~ImageNode();
	void SetImage(ImageName::Name imageName, TextName::Name textName, Rect rect);
	ImageName::Name GetImageName() const;
	Image *GetImage();

private:
	Image *pImage;
};


#endif