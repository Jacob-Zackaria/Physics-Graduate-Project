#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Keyboard.h"
#include "Mouse.h"
#include "InputSystem.h"
#include "Box2D.h"

class InputManager
{
	

public:
	
	enum class PositionState
	{
		INSIDE,
		OUTSIDE,
		UNKNOWN
	};

	enum class MouseState
	{
		RIGHT,
		LEFT,
		MIDDLE,
		NONE
	};

	InputManager(const InputManager&) = delete;
	const InputManager& operator = (const InputManager&) = delete;
	~InputManager();
	static void Terminate();
	static void AddInputs(InputSystem* pNewObj, const InputSystem::InputType newType);
	static void Update();
	static InputSystem* Find(const InputSystem::InputType newType);
	static void Delete(const InputSystem::InputType newType);
	static MouseState GetMouseState();
	static b2Vec2 GetMouseWorld();
	static b2Vec2 GetMouseLocal();

private:
	static InputManager* privGetInstance();
	InputManager();

	// check if mouse key is pressed.
	void CheckMouseState();

	void privAddToFront(InputSystem* node, InputSystem*& head);
	void privRemove(InputSystem* pNewData, InputSystem*& pHead);

	InputSystem* pSystems;
	MouseState mState;
};

#endif INPUT_MANAGER_H