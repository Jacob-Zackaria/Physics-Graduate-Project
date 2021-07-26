#include "InputManager.h"
#include "ObjectFactory.h"
#include "PixelToMeter.h"
#include "LineCollider.h"
LineCollider::LineCollider(Color::Type newColor)
	:
	pGrObj(new GraphicsObject_Box(Rect(0, 0, 1, 1))),
	lineInstance(nullptr),
	lineCol(newColor)
{
}

LineCollider::~LineCollider()
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


void LineCollider::Update()
{
	static bool LeftButtonDown = false;
	static b2Vec2 prevPos;
	static LineInstance* newLineInstance = nullptr;
	if ((Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT)) && !LeftButtonDown)
	{
		// begin capture
		prevPos = InputManager::GetMouseLocal();		// Start of the line

		//this->startPos = prevPos;
		
		// create new line instance.
		newLineInstance = new LineInstance(b2Vec2(PixelToMeter(prevPos.x), PixelToMeter(prevPos.y)));

		this->privAddToEnd(newLineInstance, this->lineInstance);

		//DebugMsg::out("Line: Begin\n");
		LeftButtonDown = true;
	}
	else if ((Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT)) && LeftButtonDown)
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

			// create collision box
			GameObject2D* pNewObj = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);

			// set angle
			float lineAngle = atan2f(newLine.y, newLine.x);
			pNewObj->SetOrigAngle(lineAngle);

			// add pos and gameobject for line renderer.
			b2Vec2 WorldMousePos = b2Vec2(PixelToMeter(localMousePos.x), PixelToMeter(localMousePos.y));
			newLineInstance->Add(pNewObj, WorldMousePos);

			// set prev position as current position.
			LeftButtonDown = true;
			prevPos = localMousePos; // next line's start point
		}

	}
	else if (!(Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT)) && LeftButtonDown)
	{
		//DebugMsg::out("Line: End\n");
		LeftButtonDown = false;
	}
}

void LineCollider::Render()
{
	// render each line instances.
	LineInstance* pNewLink = this->lineInstance;
	while (pNewLink != nullptr)
	{
		ObjectPos* pNewPos = pNewLink->objectPos;
		b2Vec2 currPos;
		b2Vec2 prevPos = pNewLink->startPos;
		while (pNewPos != nullptr)
		{
			currPos = pNewPos->pos;
			DrawSegment(prevPos, currPos);
			prevPos = currPos;
			pNewPos = pNewPos->getNext();
		}

		// next line
		pNewLink = pNewLink->getNext();
	}
}


void LineCollider::DrawSegment(b2Vec2 s, b2Vec2 e)
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

void LineCollider::LineInstance::privAddToEnd(ObjectPos* node, ObjectPos*& head)
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

void LineCollider::LineInstance::privRemove(ObjectPos* pNewData, ObjectPos*& pHead)
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

void LineCollider::privAddToEnd(LineInstance* node, LineInstance*& head)
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

void LineCollider::privRemove(LineInstance* pNewData, LineInstance*& pHead)
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

