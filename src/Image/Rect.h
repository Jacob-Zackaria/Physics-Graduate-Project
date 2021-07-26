#ifndef RECT_H
#define RECT_H

struct Rect
{
	Rect( float x, float y, float width, float height);
	bool operator == (const Rect& newRect);
	Rect();

	void clear();

	float x;
	float y;
	float width;
	float height;
};


#endif