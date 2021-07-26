#ifndef LANDER_INPUT_H
#define LANDER_INPUT_H

#include "InputSystem.h"
#include "GameObjectMan.h"

class LanderInput : InputSystem
{
public:
	LanderInput(GameObject2D* newGameObject);
	LanderInput(const LanderInput&) = delete;
	const LanderInput& operator = (const LanderInput&) = delete;
	virtual ~LanderInput();

	virtual void Update() override;
private:

	GameObject2D* pGobj;
};


#endif LANDER_INPUT_H