#include "InputManager.h"
#include "PixelToMeter.h"
#include "Game.h"
#include "CameraMan.h"


InputManager::InputManager()
	:
	pSystems(nullptr),
	mState(MouseState::NONE)
{
}

void InputManager::CheckMouseState()
{
	InputManager* pMan = InputManager::privGetInstance();

	// Check mouse state
	static bool mLeftPressed = false;
	static bool mRightPressed = false;
	static bool mMiddlePressed = false;
	mLeftPressed = Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT);
	mRightPressed = Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT);
	mMiddlePressed = Mouse::GetKeyState(AZUL_MOUSE::BUTTON_MIDDLE);
	if (mLeftPressed)
	{
		pMan->mState = MouseState::LEFT;
	}
	else if (mRightPressed)
	{
		pMan->mState = MouseState::RIGHT;
	}
	else if (mMiddlePressed)
	{
		pMan->mState = MouseState::MIDDLE;
	}
	else
	{
		pMan->mState = MouseState::NONE;
	}
}

InputManager::~InputManager()
{
}

void InputManager::Terminate()
{
	InputManager* pMan = InputManager::privGetInstance();

	InputSystem* pTmp = pMan->pSystems;
	InputSystem* pTmp2 = nullptr;
	while (pTmp != nullptr)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->getNext();
		delete pTmp2;
	}
}

void InputManager::AddInputs(InputSystem* pNewObj, InputSystem::InputType newType)
{
	InputManager* pMan = InputManager::privGetInstance();

	pNewObj->SetType(newType);

	pMan->privAddToFront(pNewObj, pMan->pSystems);
}

void InputManager::Update()
{
	InputManager* pMan = InputManager::privGetInstance();

	pMan->CheckMouseState();

	InputSystem* pTmp = pMan->pSystems;

	while (pTmp != nullptr)
	{
		pTmp->Update();
		pTmp = pTmp->getNext();
	}
}

InputSystem* InputManager::Find(const InputSystem::InputType newType)
{
	InputManager* pMan = InputManager::privGetInstance();

	InputSystem* pTmp = pMan->pSystems;

	while (pTmp != nullptr)
	{
		if (pTmp->GetType() == newType)
		{
			return (pTmp);
		}
		pTmp = pTmp->getNext();
	}

	return nullptr;
}

void InputManager::Delete(const InputSystem::InputType newType)
{
	InputManager* pMan = InputManager::privGetInstance();

	InputSystem* pTmp = pMan->pSystems;
	InputSystem* pTmp2 = nullptr;
	while (pTmp != nullptr)
	{
		if (pTmp->GetType() == newType)
		{
			pTmp2 = pTmp;
			pTmp = pTmp->getNext();
			pMan->privRemove(pTmp2, pMan->pSystems);
			delete pTmp2;
		}
		else
		{
			pTmp = pTmp->getNext();
		}
	}
}


InputManager::MouseState InputManager::GetMouseState()
{
	InputManager* pMan = InputManager::privGetInstance();
	return (pMan->mState);
}


InputManager* InputManager::privGetInstance()
{
	static InputManager instance;
	return &instance;
}


void InputManager::privAddToFront(InputSystem* node, InputSystem*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setNext(nullptr);
		node->setPrev(nullptr);
	}
	else
	{
		node->setNext(head);
		head->setPrev(node);
		head = node;
	}
}

void InputManager::privRemove(InputSystem* pNewData, InputSystem*& pHead)
{
	//Check if node to delete has a next or prev links.
	if (pNewData->getNext() == nullptr && pNewData->getPrev() == nullptr)
	{
		pHead = nullptr;
	}
	else if (pNewData->getPrev() == nullptr)    //Check if there is a prev link. 
	{
		pHead = pHead->getNext();
		pHead->setPrev(nullptr);
	}
	else if (pNewData->getNext() == nullptr)    //Check if there is a next link.
	{
		pNewData->getPrev()->setNext(nullptr);
	}
	else                    //If no next or prev links are present.
	{
		pNewData->getPrev()->setNext(pNewData->getNext());
		pNewData->getNext()->setPrev(pNewData->getPrev());
	}

	//Clear links of deleted node.
	pNewData->setNext(nullptr);
	pNewData->setPrev(nullptr);
}

b2Vec2 InputManager::GetMouseWorld()
{
	// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);
	Camera* pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);

	//// Important: inverts the y values to get 0,0 at bottom left.
	yPos = Game::GetWindowHeight() - yPos;

	Vect campos;
	pCam->getPos(campos);

	float currwidth = pCam->getMaxX() - pCam->getMinX();
	float ScaleFactorX = currwidth / pCam->getScreenWidth();
	xPos = ScaleFactorX * xPos - .5f * (currwidth - pCam->getScreenWidth()) + campos[x];

	float currheight = pCam->getMaxY() - pCam->getMinY();
	float ScaleFactorY = currheight / pCam->getScreenHeight();
	yPos = ScaleFactorY * yPos - .5f * (currheight - pCam->getScreenHeight()) + campos[y];

	//DebugMsg::out("Bird: x = %f, y = %f \tMouse: x = %f, y = %f\n", pGobj->posX, pGobj->posY, xPos, yPos );

	return b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));
}

b2Vec2 InputManager::GetMouseLocal()
{
	// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);
	Camera* pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);

	//// Important: inverts the y values to get 0,0 at bottom left.
	yPos = Game::GetWindowHeight() - yPos;

	Vect campos;
	pCam->getPos(campos);

	float currwidth = pCam->getMaxX() - pCam->getMinX();
	float ScaleFactorX = currwidth / pCam->getScreenWidth();
	xPos = ScaleFactorX * xPos - .5f * (currwidth - pCam->getScreenWidth()) + campos[x];

	float currheight = pCam->getMaxY() - pCam->getMinY();
	float ScaleFactorY = currheight / pCam->getScreenHeight();
	yPos = ScaleFactorY * yPos - .5f * (currheight - pCam->getScreenHeight()) + campos[y];

	//DebugMsg::out("Bird: x = %f, y = %f \tMouse: x = %f, y = %f\n", pGobj->posX, pGobj->posY, xPos, yPos );

	return b2Vec2(xPos, yPos);
}
