#include "ImpulseInput.h"
#include "PixelToMeter.h"
#include "InputManager.h"

ImpulseInput::ImpulseInput(const float& newScreenHgt)
	:screenHgt(newScreenHgt),
	testList(nullptr)
{
}

ImpulseInput::~ImpulseInput()
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

void ImpulseInput::AddToTestList(GameObject2D* pNewObj)
{
	// create new link
	TestLink* pNewLink = new TestLink(pNewObj);

	this->privAddToFront(pNewLink, this->testList);
}

void ImpulseInput::Update()
{
	TestLink* pTest = this->testList;

	// traverse test objects
	while (pTest != nullptr)
	{

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

		if (mState == InputManager::MouseState::RIGHT && pstate == PositionState::INSIDE)
		{
			pTest->bodyState = TestLink::BirdState::IMPULSE;
			pBody->SetActive(false);
			// to reset all movement
			//pBody->SetAwake(false);
		}


		if (mState == InputManager::MouseState::RIGHT)
		{
			if (pTest->bodyState == TestLink::BirdState::IMPULSE)
			{
				pTest->bodyState = TestLink::BirdState::NORMAL;
				b2Vec2 dir(1, 2);
				dir.Normalize();
				const float mag = 15.0f;
				b2Vec2 imp = mag * dir;

				//pBody->ApplyForceToCenter(b2Vec2(0, 12 * pBody->GetMass()), true);
				pBody->ApplyLinearImpulse(imp, pBody->GetWorldCenter(), true);

				pBody->SetActive(true);
			}
		}

		// next test
		pTest = pTest->getNext();
	}
}

void ImpulseInput::privAddToFront(TestLink* node, TestLink*& head)
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
