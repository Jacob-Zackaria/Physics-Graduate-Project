#include "InputSystem.h"
void InputSystem::SetType(const InputType newType)
{
	this->pType = newType;
}

const InputSystem::InputType& InputSystem::GetType() const
{
	return (this->pType);
}
