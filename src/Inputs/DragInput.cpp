#include "DragInput.h"
#include "PixelToMeter.h"
#include "InputManager.h"

DragInput::DragInput(const float& newScreenHgt)
	:
	screenHgt(newScreenHgt),
	testList(nullptr),
	isDragged(false),
	pDraggingElement(nullptr)
{
}

DragInput::~DragInput()
{
	TestLink* pTmp = this->testList;
	TestLink* pTmp2 = nullptr;
	while (pTmp != nullptr)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->getNext();
		delete pTmp2;
	}
}

void DragInput::AddToTestList(GameObject2D* pNewObj)
{
	// create new link
	TestLink* pNewLink = new TestLink(pNewObj);

	this->privAddToFront(pNewLink, this->testList);
}

void DragInput::Update()
{
	TestLink* pTest = this->testList;

	// traverse test objects
	while (pTest != nullptr)
	{
		// check if an element is dragged.
		if (this->isDragged && pTest != this->pDraggingElement)
		{
			// if yes, skip execution of other elements other than the dragged element
			// next test
			pTest = pTest->getNext();
			continue;
		}

		// get corresponding gameobject
		GameObject2D* pGobj = pTest->GetGameObject();
		PositionState pstate = PositionState::UNKNOWN;

		// check mouse state
		InputManager::MouseState mState = InputManager::GetMouseState();

		// get mouse position
		float xPos;
		float yPos;
		Mouse::GetCursor(xPos, yPos);

		//// Important: inverts the y values to get 0,0 at bottom left.
		yPos = screenHgt - yPos;

		// get world mouse pos
		b2Vec2 WorldMousePos = b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));
		// inside bird?
		b2Body* pBody = pGobj->GetBody();
		// check all fixtures
		b2Fixture* pFix = pBody->GetFixtureList();
		while (pFix != nullptr)
		{
			if (pFix->TestPoint(WorldMousePos))
			{
				pstate = PositionState::INSIDE;
				break;
			}

			pFix = pFix->GetNext();
		}
		if (pFix == nullptr)
		{
			pstate = PositionState::OUTSIDE;
		}

		// to avoid moving body origin to mouse click point
		static Vect2D differneceVec;
		if (mState == InputManager::MouseState::LEFT && pstate == PositionState::INSIDE && !this->isDragged)
		{
			// calculate difference of mouse point and body position.
			differneceVec = Vect2D(MeterToPixel(pBody->GetPosition().x) - xPos, MeterToPixel(pBody->GetPosition().y) - yPos);

			// this object is being dragged
			this->isDragged = true;
			this->pDraggingElement = pTest;
			pTest->bodyState = TestLink::BirdState::DRAGGED;
			pBody->SetActive(false);
			// to reset all movement
			pBody->SetAwake(false);
		}


		if (mState == InputManager::MouseState::LEFT)
		{
			if (pTest->bodyState == TestLink::BirdState::DRAGGED)
			{
				// change object position according to mouse point
				b2Vec2 newPos(PixelToMeter(xPos + differneceVec.x), PixelToMeter(yPos + differneceVec.y));
				pBody->SetTransform(newPos, pBody->GetAngle());
			}
		}
		else
		{
			// if mouse state is changed, dont drag
			this->isDragged = false;
			pTest->bodyState = TestLink::BirdState::NORMAL;
			pBody->SetAwake(true);
			pBody->SetActive(true);
		}

		// next test
		pTest = pTest->getNext();
	}
}

const bool DragInput::Find(GameObject2D* pNewObj)
{
	if (this->testList)
	{
		TestLink* pTmp = this->testList;
		while (pTmp != nullptr)
		{
			if (pTmp->GetGameObject()->getName() == pNewObj->getName())
			{
				return true;
			}
			pTmp = pTmp->getNext();
		}
	}
		
	return false;
}

void DragInput::privAddToFront(TestLink* node, TestLink*& head)
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
