#ifndef IMPULSE_INPUT_H
#define IMPULSE_INPUT_H

#include "InputSystem.h"
#include "TestLink.h"

class ImpulseInput : InputSystem
{
	enum class PositionState
	{
		INSIDE,
		OUTSIDE,
		UNKNOWN
	};
public:
	ImpulseInput(const float& newScreenHgt);
	ImpulseInput(const ImpulseInput&) = delete;
	const ImpulseInput& operator = (const ImpulseInput&) = delete;
	virtual ~ImpulseInput();

	void AddToTestList(GameObject2D* pNewObj);
	virtual void Update() override;
private:
	void privAddToFront(TestLink* node, TestLink*& head);

	float screenHgt;
	TestLink* testList;
};


#endif IMPULSE_INPUT_H