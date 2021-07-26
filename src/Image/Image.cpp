#include "TextureMan.h"
#include "Image.h"
#include "Rect.h"
#include "ImageName.h"


// public methods: -------------------------------------------------------------

Image::Image()
{
	this->name = ImageName::Name::Not_Initialized;
	this->imageRect.clear();
	this->pText = 0;
}

Image::Image(ImageName::Name _imageName, Texture *_pText, Rect _rect)
{
	this->name = _imageName;
	this->pText = _pText;
	this->imageRect = _rect;
}

Image::Image(ImageName::Name _imageName, TextName::Name _textName, Rect _rect)
{
	this->name = _imageName;
	this->pText = TextureMan::findTexture(_textName);
	this->imageRect = _rect;
}

void Image::Set(ImageName::Name _imageName, Texture *_pText, Rect _rect)
{
	this->name = _imageName;
	this->pText = _pText;
	this->imageRect = _rect;
}

void Image::Set(ImageName::Name _imageName, TextName::Name _textName, Rect _rect)
{
	this->name = _imageName;
	this->pText = TextureMan::findTexture(_textName);
	this->imageRect = _rect;
}


EnumBase Image::getName()
{
	return ImageName((EnumBase::Name)this->name);
}