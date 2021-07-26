#include <stdlib.h>
#include <assert.h>

#include "ImageNode.h"
#include "ImageMan.h"

ImageMan::ImageMan()
{
	this->active = 0;
}

ImageMan * ImageMan::privGetInstance()
{
	// This is where its actually stored (BSS section)
	static ImageMan imageMan;
	return &imageMan;
}

void ImageMan::addImage(ImageName::Name _imageName, TextName::Name _textName, Rect _rect)
{
	// Get the instance to the manager
	ImageMan *pImageMan = ImageMan::privGetInstance();

	// Create a TextureNode
	ImageNode *pNode = new ImageNode();

	// initialize it
	pNode->SetImage(_imageName, _textName, _rect);

	// Now add it to the manager
	pImageMan->privAddToFront(pNode, pImageMan->active);
}


Image *ImageMan::GetImage(const ImageName::Name _name)
{
	// Get the instance to the manager
	ImageMan *pImageMan = ImageMan::privGetInstance();
	ImageNode *pNode = (ImageNode *)pImageMan->active;
	while (pNode != 0)
	{
		if (pNode->GetImageName() == _name)
		{
			// found it
			break;
		}
		pNode = (ImageNode *)pNode->next;
	}
	return pNode->GetImage();
}

void ImageMan::Terminate()
{
	// Get the instance to the manager
	ImageMan *pImgMan = ImageMan::privGetInstance();
	ImageNode *pNode = (ImageNode *)pImgMan->active;
	while (pNode != 0)
	{
		// bye bye
		ImageNode* pTmp = pNode;
		// next
		pNode = (ImageNode *)pNode->next;
		delete pTmp;
	}
}

void ImageMan::privAddToFront(ImageNodeLink *node, ImageNodeLink *&head)
{
	assert(node != 0);
	if (head == 0)
	{
		head = node;
		node->next = 0;
		node->prev = 0;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
}
