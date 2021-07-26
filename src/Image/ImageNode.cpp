#include <string.h>

#include "ImageNode.h"
#include "ImageName.h"
#include "TextureName.h"

ImageNode::ImageNode()
{
	pImage = new Image();
}

ImageNode::~ImageNode()
{
	delete pImage;
}

void ImageNode::SetImage(ImageName::Name imageName, TextName::Name textName, Rect rect)
{
	pImage->Set(imageName, textName, rect);
}

ImageName::Name ImageNode::GetImageName() const
{
	return pImage->name;
}

Image *ImageNode::GetImage()
{
	return pImage;
}