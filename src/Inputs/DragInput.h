#ifndef DRAG_INPUT_H
#define DRAG_INPUT_H

#include "InputSystem.h"
#include "TestLink.h"

class DragInput : InputSystem
{
	enum class PositionState
	{
		INSIDE,
		OUTSIDE,
		UNKNOWN
	};
public:
	DragInput(const float& newScreenHgt);
	DragInput(const DragInput&) = delete;
	const DragInput& operator = (const DragInput&) = delete;
	virtual ~DragInput();

	void AddToTestList(GameObject2D* pNewObj);
	virtual void Update() override;
	const bool Find(GameObject2D* pNewObj);

private:
	void privAddToFront(TestLink* node, TestLink*& head);

	float screenHgt;
	TestLink* testList;
	bool isDragged;
	TestLink* pDraggingElement;
};


#endif DRAG_INPUT_H