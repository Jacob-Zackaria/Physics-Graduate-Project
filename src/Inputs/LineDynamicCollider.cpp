#include "InputManager.h"
#include "ObjectFactory.h"
#include "PixelToMeter.h"
#include "LineDynamicCollider.h"
LineDynamicCollider::LineDynamicCollider(Color::Type newColor)
	:
	pGrObj(new GraphicsObject_Box(Rect(0, 0, 1, 1))),
	lineInstance(nullptr),
	lineCol(newColor)
{
}

LineDynamicCollider::~LineDynamicCollider()
{
	LineInstance* newGame = this->lineInstance;
	LineInstance* new2 = nullptr;
	while (newGame != nullptr)
	{
		new2 = newGame;
		newGame = newGame->getNext();
		this->privRemove(new2, this->lineInstance);
		delete new2;
	}

	delete pGrObj;
}


void LineDynamicCollider::Update()
{
	static bool LeftButtonDown = false;
	static b2Vec2 prevPos;
	static LineInstance* newLineInstance = nullptr;
	if ((Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT)) && !LeftButtonDown)
	{
		// begin capture
		prevPos = InputManager::GetMouseLocal();		// Start of the line
		
		// create new line instance.
		newLineInstance = new LineInstance();

		// create dynamic collision box
		GameObject2D* mainBody = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), Rect(prevPos.x, prevPos.y, 1.0f, 1.0f), true);

		// attach main body.
		newLineInstance->mainBody = mainBody;

		// add to list
		this->privAddToEnd(newLineInstance, this->lineInstance);

		//DebugMsg::out("Line: Begin\n");
		LeftButtonDown = true;
	}
	else if ((Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT)) && LeftButtonDown)
	{
		// continue capture
		b2Vec2 localMousePos = InputManager::GetMouseLocal(); // End of the line

		// get line
		b2Vec2 newLine = (localMousePos - prevPos);

		// If mouse has actually moved
		if (newLine.LengthSquared() > 2.0f)
		{
			// find length of line
			float lineLength = newLine.Length();

			// find position of stick
			b2Vec2 differenceVector = (prevPos - localMousePos);
			b2Vec2 stickPos = prevPos - (0.5f * differenceVector);

			// rect
			Rect rect = Rect(stickPos.x, stickPos.y, lineLength, 2.0f);

			// create collision box fixture
			GameObject2D* pNewObj = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, false);

			// get angle
			float lineAngle = atan2f(newLine.y, newLine.x);

			// crete fixture in main body.
			b2Vec2 fixPos = b2Vec2((stickPos.x - newLineInstance->mainBody->GetPosX()), (stickPos.y - newLineInstance->mainBody->GetPosY()));
			newLineInstance->mainBody->GetPhysicsObject()->CreateShapeAndFixture(pNewObj, b2Vec2(PixelToMeter(fixPos.x), PixelToMeter(fixPos.y)), lineAngle);

			// set gameObject offset angle.
			pNewObj->SetOffsetAngle(lineAngle);
			
			// add gameobject for line renderer.
			newLineInstance->Add(pNewObj);

			// set prev position as current position.
			LeftButtonDown = true;
			prevPos = localMousePos; // next line's start point
		}

	}
	else if (!(Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT)) && LeftButtonDown)
	{
		//DebugMsg::out("Line: End\n");
		LeftButtonDown = false;

		// make dynamic
		newLineInstance->mainBody->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	}
	else if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT))
	{
		// get each line.
		LineInstance* pNewLink = this->lineInstance;
		while (pNewLink != nullptr)
		{
			LineInstance* pDel = pNewLink;
			// next line
			pNewLink = pNewLink->getNext();

			// get world mouse pos
			b2Vec2 WorldMousePos = InputManager::GetMouseWorld();

			// inside bird?
			b2Body* pBody = pDel->mainBody->GetBody();
			// check all fixtures
			b2Fixture* pFix = pBody->GetFixtureList();
			while (pFix != nullptr)
			{
				if (pFix->TestPoint(WorldMousePos))
				{
					this->privRemove(pDel, this->lineInstance);
					delete pDel;
					break;
				}

				pFix = pFix->GetNext();
			}
		}
	}
}

void LineDynamicCollider::Render()
{
	// render each line instances.
	LineInstance* pNewLink = this->lineInstance;
	while (pNewLink != nullptr)
	{
		ObjectPos* pNewPos = pNewLink->objectPos;
		b2Vec2 mainPos = pNewLink->mainBody->GetBody()->GetPosition();
		b2Vec2 currPos;
		b2Vec2 prevPos = mainPos;
		while (pNewPos != nullptr)
		{
			currPos = b2Vec2(PixelToMeter(pNewPos->gameObj->GetPosX()), PixelToMeter(pNewPos->gameObj->GetPosY()));
			DrawSegment(prevPos, currPos);
			prevPos = currPos;
			pNewPos = pNewPos->getNext();
		}

		// next line
		pNewLink = pNewLink->getNext();
	}
}


void LineDynamicCollider::DrawSegment(b2Vec2 s, b2Vec2 e)
{
	b2Vec2 v = (e - s);
	float len = MeterToPixel(v.Length());
	b2Vec2 pos = .5f * (s + e);
	float ang = atan2f(v.y, v.x);

	pGrObj->color = lineCol;

	Matrix Scale(MatrixScaleType::SCALE, len, 1, 1);
	Matrix Rot(RotType::ROT_Z, ang);
	Matrix Trans(MatrixTransType::TRANS, MeterToPixel(pos.x), MeterToPixel(pos.y), 0.0f);

	Matrix W = Scale * Rot * Trans;

	pGrObj->SetWorld(W);

	pGrObj->Render();
}


void LineDynamicCollider::LineInstance::privAddToEnd(ObjectPos* node, ObjectPos*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setPrev(nullptr);
	}
	else
	{
		ObjectPos* pTmp = head;
		while (pTmp->getNext() != nullptr)
		{
			pTmp = pTmp->getNext();
		}
		node->setPrev(pTmp);
		pTmp->setNext(node);
	}
	node->setNext(nullptr);
}

void LineDynamicCollider::LineInstance::privRemove(ObjectPos* pNewData, ObjectPos*& pHead)
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

void LineDynamicCollider::privAddToEnd(LineInstance* node, LineInstance*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setPrev(nullptr);
	}
	else
	{
		LineInstance* pTmp = head;
		while (pTmp->getNext() != nullptr)
		{
			pTmp = pTmp->getNext();
		}
		node->setPrev(pTmp);
		pTmp->setNext(node);
	}
	node->setNext(nullptr);
}

void LineDynamicCollider::privRemove(LineInstance* pNewData, LineInstance*& pHead)
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

