#ifndef ROPE_H
#define ROPE_H

#include "SceneLink.h"
#include <vector>
class Rope
{
public:
	Rope() = delete;
	Rope(const Rope&) = delete;
	const Rope& operator = (const Rope&) = delete;
	~Rope();

	Rope(b2Vec2 newStart, GameObject2D* newEnd, const uint_fast16_t segmentNo, bool lineRender = false, Color::Type newColor = Color::Type::Red);
	void Render();

private:

	void DrawSegment(b2Vec2 s, b2Vec2 e);

	void privAddToEnd(SceneLink* node, SceneLink*& head);
	void privRemove(SceneLink* pNewData, SceneLink*& pHead);
	void Add(GameObject2D* newObj);

	GraphicsObject_Box* pGrObj;
	GameObject2D* pEndObject;
	SceneLink* gameObj;
	Color::Type lineCol;
};

#endif ROPE_H