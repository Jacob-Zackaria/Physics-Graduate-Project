#ifndef IMAGE_H
#define IMAGE_H

#include "Rect.h"
#include "Texture.h"
#include "ImageName.h"


class Image 
{

public:
	// public methods: -------------------------------------------------------------
	Image();
	Image(ImageName::Name imageName, TextName::Name textName, Rect rect);
	Image(ImageName::Name imageName, Texture *pTexture, Rect rect);

	void Set(ImageName::Name imageName, TextName::Name textName, Rect rect);
	void Set(ImageName::Name imageName, Texture *pTexture, Rect rect);
	EnumBase getName();

public:
	// data: -----------------------------------------------------------------------
	ImageName::Name	name;
	Texture			*pText;
	Rect			imageRect;
};




#endif