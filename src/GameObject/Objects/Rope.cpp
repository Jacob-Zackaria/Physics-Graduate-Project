#include "Rope.h"
#include "PixelToMeter.h"
#include "ObjectFactory.h"
#include "Wood.h"

Rope::~Rope()
{
	SceneLink* newGame = this->gameObj;
	SceneLink* new2 = nullptr;
	while (newGame != nullptr)
	{
		new2 = newGame;
		newGame = newGame->getNext();
		this->privRemove(new2, this->gameObj);
		delete new2;

	}

	delete pGrObj;
}

Rope::Rope(b2Vec2 newStart, GameObject2D*  newEnd, const uint_fast16_t segmentNo, bool lineRender, Color::Type newColor)
	:
	pEndObject(newEnd),
	gameObj(nullptr),
	lineCol(newColor)
{
	pGrObj = new GraphicsObject_Box(Rect(0, 0, 1, 1));

	b2Vec2 endPos = b2Vec2(newEnd->GetPosX(), newEnd->GetPosY());
	float stickLength = ((endPos - newStart).Length()) / segmentNo;
	b2Vec2 stickPos = {};
	GameObject2D* pNewObj = nullptr;
	b2RevoluteJointDef rjdef;
	b2RopeJointDef ropejdef;
	b2Body* currBody = nullptr;
	b2Body* prevBody = newEnd->GetBody();

	for (uint_fast16_t i = 0; i < segmentNo; i++)
	{
		
		stickPos = endPos - b2Vec2(0, ((i * stickLength) + stickLength));
		

		// create new stick
		Rect rect = Rect(stickPos.x, stickPos.y, stickLength, 2.0f);

		if (lineRender)
		{
			pNewObj = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
		}
		else
		{
			pNewObj = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
			Wood* pWoodObj = (Wood*)pNewObj;
			pWoodObj->SetDamagable(false);
		}
		
		
		pNewObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		pNewObj->SetOrigAngle(MATH_PI2);
		
		this->Add(pNewObj);

		currBody = pNewObj->GetBody();

		// Link it up with previous body
		//*
		rjdef.Initialize(
			prevBody,
			currBody,
			currBody->GetWorldPoint(b2Vec2(PixelToMeter(stickLength / 2.0f), 0))
		);


		PhysicsManager::GetWorld()->CreateJoint(&rjdef);
		////*/


		//*
		// rope joint: Attempt #2 (better)
		ropejdef.bodyA = newEnd->GetBody();		// all reference from _ceiling_
		ropejdef.bodyB = currBody;
		ropejdef.localAnchorA.Set(0, 0);
		ropejdef.localAnchorB.Set(0, 0);
		ropejdef.maxLength = PixelToMeter((float)(i + 1) * stickLength); // length in meters!

		PhysicsManager::GetWorld()->CreateJoint(&ropejdef);
		//*/
		
		//// prepare for next joint
		prevBody = currBody;
		currBody = nullptr;

	}
}

void Rope::Render()
{
	SceneLink* pNewLink = this->gameObj;
	b2Body* currBody = nullptr;
	b2Body* prevBody = pEndObject->GetBody();
	while (pNewLink != nullptr)
	{
		currBody = pNewLink->GetGameObject()->GetBody();
		DrawSegment(prevBody->GetPosition(), currBody->GetPosition());
		prevBody = currBody;
		pNewLink = pNewLink->getNext();
	}
}


void Rope::DrawSegment(b2Vec2 s, b2Vec2 e)
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



void Rope::privAddToEnd(SceneLink* node, SceneLink*& head)
{
	assert(node);

	if (head == nullptr)
	{
		head = node;
		node->setPrev(nullptr);
	}
	else
	{
		SceneLink* pTmp = head;
		while (pTmp->getNext() != nullptr)
		{
			pTmp = pTmp->getNext();
		}
		node->setPrev(pTmp);
		pTmp->setNext(node);
	}
	node->setNext(nullptr);
}

void Rope::privRemove(SceneLink* pNewData, SceneLink*& pHead)
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


void Rope::Add(GameObject2D* newObj)
{
	SceneLink* newGameObj = new SceneLink(newObj);

	this->privAddToEnd(newGameObj, this->gameObj);
}

