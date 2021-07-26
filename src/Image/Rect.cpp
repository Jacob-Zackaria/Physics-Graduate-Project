#include "Rect.h"


Rect::Rect( float _x, float _y, float _width, float _height)
	: x(_x), y(_y), width(_width), height(_height)
{

}

bool Rect::operator==(const Rect& newRect)
{
	bool status = true;

	if (this->x != newRect.x)
	{
		status = false;
	}
	if (this->y != newRect.y)
	{
		status = false;
	}
	if (this->width != newRect.width)
	{
		status = false;
	}
	if (this->height != newRect.height)
	{
		status = false;
	}

	return status;
}

Rect::Rect( )
	: x(0.0f), y(0.0f), width(0.0f), height(0.0f)
{

}

void Rect::clear()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->height = 0.0f;
	this->width = 0.0f;
}