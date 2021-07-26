#include "SaltSalt.h"
#include "InputManager.h"
SaltSalt::SaltSalt()
	:pCircles()
{
}

SaltSalt::~SaltSalt()
{
}

void SaltSalt::Update()
{
	static bool RightButtonDown = false;

	if ((Mouse::GetKeyState(AZUL_MOUSE::BUTTON_MIDDLE)) && !RightButtonDown)
	{
		
		RightButtonDown = true;
	}
	else if ((Mouse::GetKeyState(AZUL_MOUSE::BUTTON_MIDDLE)) && RightButtonDown)
	{
		b2Vec2 localMousePos = InputManager::GetMouseLocal();

		pCircles.Create(localMousePos.x, localMousePos.y, 0.0f);
	}
	else if (!(Mouse::GetKeyState(AZUL_MOUSE::BUTTON_MIDDLE)) && RightButtonDown)
	{
		
		RightButtonDown = false;

	}
}
