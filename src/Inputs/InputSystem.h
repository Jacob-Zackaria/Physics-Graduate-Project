#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

class InputSystem
{
public:
	enum class InputType
	{
		NONE,
		DRAG_INPUT,
		IMPULSE_INPUT,
		LANDER_INPUT,
		LEVEL_SELECTOR,
		SLING_DRAG,
		TOWER_INPUT,
		RAY_CAST_QUERY,
		AABB_QUERY,
		LINE_COLLIDER,
		LINE_DYNAMIC_COLLIDER,
		SALT_SALT
	};

	InputSystem()
		: pType(InputType::NONE),
		pNext(nullptr), pPrev(nullptr)
	{}
	InputSystem(const InputSystem&) = delete;
	const InputSystem& operator = (const InputSystem&) = delete;
	virtual ~InputSystem()
	{}

	virtual void Update() = 0;

	//-----links----
	void InputSystem::setNext(InputSystem* newNext)
	{
		this->pNext = newNext;
	}

	void InputSystem::setPrev(InputSystem* newPrev)
	{
		this->pPrev = newPrev;
	}

	InputSystem* InputSystem::getNext() const
	{
		return (this->pNext);
	}

	InputSystem* InputSystem::getPrev() const
	{
		return (this->pPrev);
	}

	void SetType(const InputType newType);

	const InputType& GetType() const;

private:
	InputType pType;
	InputSystem* pNext;
	InputSystem* pPrev;
};


#endif INPUT_SYSTEM_H