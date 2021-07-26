#include <assert.h>

#include "MathEngine.h"
#include "GameObject.h"

#include "GameObject2D.h"
#include "GraphicsObject_Sprite.h"
#include "AzulHelper.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "Model.h"
#include "PixelToMeter.h"
#include "GameObjectMan.h"
#include "PhysicsManager.h"

GameObject2D::GameObject2D(GameObjectName::Name _name)
	:
	pGameSprite(nullptr),
	pDebugSprite(nullptr),
	DebugShape(DEBUG_SHAPE::Box),
	name(_name),
	drawSprite(false),
	drawDebug(false),
	pNext(nullptr),
	pPrev(nullptr),
	pPhyObj(nullptr),
	scaleX(1.0f),
	scaleY(1.0f),
	posX(0.0f),
	posY(0.0f),
	currAngle(0.0f),
	offsetAngle(0.0f),
	sortBucket(GameObjectName::Name::NOT_INITIALIZED)
{
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite* pGraphicsObject, GraphicsObject_Tri* graphicsObject_Tri)
	:
	pGameSprite(nullptr),
	pDebugSprite(nullptr),
	DebugShape(DEBUG_SHAPE::Triangle),
	name(_name),
	drawSprite(false),
	drawDebug(false),
	pNext(nullptr),
	pPrev(nullptr),
	pPhyObj(nullptr),
	scaleX(1.0f),
	scaleY(1.0f),
	posX(0.0f),
	posY(0.0f),
	currAngle(0.0f),
	offsetAngle(0.0f),
	sortBucket(GameObjectName::Name::NOT_INITIALIZED)
{
	//assert(pGraphicsObject != nullptr);
	assert(graphicsObject_Tri != nullptr);

	this->privBuilder(_name, pGraphicsObject, graphicsObject_Tri, DEBUG_SHAPE::Triangle);
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite  *pGraphicsObject, GraphicsObject_Box *graphicsObject_Box)
	:
	pGameSprite(nullptr),
	pDebugSprite(nullptr),
	DebugShape(DEBUG_SHAPE::Box),
	name(_name),
	drawSprite(false),
	drawDebug(false),
	pNext(nullptr),
	pPrev(nullptr),
	pPhyObj(nullptr),
	scaleX(1.0f),
	scaleY(1.0f),
	posX(0.0f),
	posY(0.0f),
	currAngle(0.0f),
	offsetAngle(0.0f),
	sortBucket(GameObjectName::Name::NOT_INITIALIZED)
{
	//assert(pGraphicsObject != nullptr);
	assert(graphicsObject_Box != nullptr);

	this->privBuilder(_name, pGraphicsObject, graphicsObject_Box, DEBUG_SHAPE::Box);
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite *graphicsObject, GraphicsObject_Circle *graphicsObject_Circle)
	:
	pGameSprite(nullptr),
	pDebugSprite(nullptr),
	DebugShape(DEBUG_SHAPE::Circle),
	name(_name),
	drawSprite(false),
	drawDebug(false),
	pNext(nullptr),
	pPrev(nullptr),
	pPhyObj(nullptr),
	scaleX(1.0f),
	scaleY(1.0f),
	posX(0.0f),
	posY(0.0f),
	currAngle(0.0f),
	offsetAngle(0.0f),
	sortBucket(GameObjectName::Name::NOT_INITIALIZED)
{
	//assert(graphicsObject != nullptr);
	assert(graphicsObject_Circle != nullptr);

	this->privBuilder(_name, graphicsObject, graphicsObject_Circle, DEBUG_SHAPE::Circle);
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite *graphicsObject)
	:
	pGameSprite(nullptr),
	pDebugSprite(nullptr),
	DebugShape(DEBUG_SHAPE::Box),
	name(_name),
	drawSprite(false),
	drawDebug(false),
	pNext(nullptr),
	pPrev(nullptr),
	pPhyObj(nullptr),
	scaleX(1.0f),
	scaleY(1.0f),
	posX(0.0f),
	posY(0.0f),
	currAngle(0.0f),
	offsetAngle(0.0f),
	sortBucket(GameObjectName::Name::NOT_INITIALIZED)
{
	assert(graphicsObject != nullptr);
	this->privBuilder(_name, graphicsObject, nullptr, DEBUG_SHAPE::Box);
}

GameObject2D::GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *pgo, DEBUG_SHAPE _shape)
	:
	pGameSprite(nullptr),
	pDebugSprite(nullptr),
	DebugShape(DEBUG_SHAPE::Box),
	name(name),
	drawSprite(false),
	drawDebug(false),
	pNext(nullptr),
	pPrev(nullptr),
	pPhyObj(nullptr),
	scaleX(1.0f),
	scaleY(1.0f),	
	posX(0.0f),
	posY(0.0f),
	currAngle(0.0f),
	offsetAngle(0.0f),
	sortBucket(GameObjectName::Name::NOT_INITIALIZED)
{
	assert(pgo != nullptr);
	Rect r;
	Vect2D xx[3] = { {0.5f, -0.5f}, {0.0f, 0.5f}, {-0.5f, -0.5f} };

	switch (_shape)
	{
	case GameObject2D::DEBUG_SHAPE::Box:
		r = Rect(pgo->origPosX, pgo->origPosY, pgo->origWidth, pgo->origHeight);
		this->privBuilder(name, pgo, new GraphicsObject_Box(r), DEBUG_SHAPE::Box);
		break;
	case GameObject2D::DEBUG_SHAPE::Circle:
		r = Rect(pgo->origPosX, pgo->origPosY, pgo->origWidth, pgo->origHeight);
		this->privBuilder(name, pgo, new GraphicsObject_Circle(r), DEBUG_SHAPE::Circle);
		break;
	case GameObject2D::DEBUG_SHAPE::Triangle:
		r = Rect(pgo->origPosX, pgo->origPosY, pgo->origWidth, pgo->origHeight);	
		this->privBuilder(name, pgo, new GraphicsObject_Tri(Vect2D(r.x, r.y), xx), DEBUG_SHAPE::Triangle);
		break;
	default:
		break;
	}
}

void GameObject2D::privBuilder(GameObjectName::Name _name, GraphicsObject_Sprite* _pgo, GraphicsObject* _pgodebug, DEBUG_SHAPE sh)
{
	this->name = _name;

	this->pGameSprite = _pgo;
	this->pDebugSprite = _pgodebug;
	this->drawSprite = true;
	this->drawDebug = false;
	this->DebugShape = sh;

	this->currAngle = 0.0f;

	if (this->pGameSprite == nullptr)
	{
		if (pDebugSprite->getModel()->Get() == ModelName::Name::Box)
		{
			GraphicsObject_Box* newDebug = (GraphicsObject_Box*)pDebugSprite;
			this->posX = newDebug->origPosX;
			this->posY = newDebug->origPosY;
		}
		else if (pDebugSprite->getModel()->Get() == ModelName::Name::Circle)
		{
			GraphicsObject_Circle* newDebug = (GraphicsObject_Circle*)pDebugSprite;
			this->posX = newDebug->origPosX;
			this->posY = newDebug->origPosY;
		}
		else if (pDebugSprite->getModel()->Get() == ModelName::Name::Tri)
		{
			GraphicsObject_Tri* newDebug = (GraphicsObject_Tri*)pDebugSprite;
			this->posX = newDebug->originPt.x;
			this->posY = newDebug->originPt.y;
		}
	}
	else
	{
		this->posX = pGameSprite->origPosX;
		this->posY = pGameSprite->origPosY;
	}

	this->scaleX = 1.0f;
	this->scaleY = 1.0f;

}

const GameObjectName::Name GameObject2D::GetBucketName() const
{
	return this->sortBucket;
}

void GameObject2D::SetBucketName(const GameObjectName::Name newName)
{
	this->sortBucket = newName;
}

const GameObject2D::DEBUG_SHAPE GameObject2D::GetDebugShape() const
{
	return this->DebugShape;
}

void GameObject2D::SetDebugColor(Color::Type col)
{
	switch (DebugShape)
	{
	case GameObject2D::DEBUG_SHAPE::Box:
		((GraphicsObject_Box*)(this->pDebugSprite))->color = col;
		break;
	case GameObject2D::DEBUG_SHAPE::Circle:
		((GraphicsObject_Circle*)(this->pDebugSprite))->color = col;
		break;
	case GameObject2D::DEBUG_SHAPE::Triangle:
		((GraphicsObject_Tri*)(this->pDebugSprite))->color = col;
		break;
	default:
		break;
	}
}

void GameObject2D::SetFixture(b2Fixture* newFix, const float newAngle, const float newPosX, const float newPosY)
{
	this->offsetAngle = newAngle;

	if (this->DebugShape == GameObject2D::DEBUG_SHAPE::Box)
	{
		b2PolygonShape* boxShape = (b2PolygonShape*)newFix->GetShape();
		boxShape->SetAsBox(PixelToMeter(this->GetOriginalWidth() * 0.5f),
			PixelToMeter(this->GetOriginalHeight() * 0.5f),
			b2Vec2(PixelToMeter(newPosX), PixelToMeter(newPosY)),
			newAngle);
	}
	else if(this->DebugShape == GameObject2D::DEBUG_SHAPE::Circle)
	{
		b2CircleShape* circleShape = (b2CircleShape*)newFix->GetShape();
		circleShape->m_p.Set(PixelToMeter(newPosX), PixelToMeter(newPosY));
		circleShape->m_radius = PixelToMeter(this->GetOriginalWidth() * 0.5f);
	}
	else
	{
		// for tri
	}
}



void GameObject2D::SetBody(b2Body* b)
{
	this->pPhyObj->SetBody(b);
}

b2Body* GameObject2D::GetBody()
{
	return this->pPhyObj->GetBody();
}

b2Fixture* GameObject2D::GetFixtureByIndex(const int i)
{
	int j = 0;
	b2Fixture* pTmp2 = nullptr;
	b2Fixture* pTmp = this->pPhyObj->GetBody()->GetFixtureList();
	while (pTmp != nullptr && j < i)
	{
		pTmp2 = pTmp;
		pTmp = pTmp->GetNext();
		j++;
	}

	return pTmp2;
}

void GameObject2D::SetScale(const float newScaleX, const float newScaleY)
{
	scaleX = newScaleX;
	scaleY = newScaleY;
}

void GameObject2D::GetScale(float& newScaleX, float& newScaleY)
{
	newScaleX = scaleX;
	newScaleY = scaleY;
}


void GameObject2D::SetPos(const float newPosX, const float newPosY)
{
	posX = newPosX;
	posY = newPosY;

	if (this->pPhyObj != nullptr)
	{
		this->pPhyObj->SetPos(newPosX, newPosY);
	}
}

void GameObject2D::GetPos(float& newPosX, float& newPosY)
{
	newPosX =posX;
	newPosY =posY;
}


const float& GameObject2D::GetOriginalWidth() const
{
	if (this->pGameSprite == nullptr)
	{
		if (pDebugSprite->getModel()->Get() == ModelName::Name::Box)
		{
			GraphicsObject_Box* newDebug = (GraphicsObject_Box*)pDebugSprite;
			return (newDebug->origWidth);
		}
		else
		{
			GraphicsObject_Circle* newDebug = (GraphicsObject_Circle*)pDebugSprite;
			return (newDebug->origWidth);
		}
	}
	else
	{
		return (this->pGameSprite->origWidth);
	}
}

const float& GameObject2D::GetOriginalHeight() const
{
	if (this->pGameSprite == nullptr)
	{
		if (pDebugSprite->getModel()->Get() == ModelName::Name::Box)
		{
			GraphicsObject_Box* newDebug = (GraphicsObject_Box*)pDebugSprite;
			return (newDebug->origHeight);
		}
		else
		{
			GraphicsObject_Circle* newDebug = (GraphicsObject_Circle*)pDebugSprite;
			return (newDebug->origHeight);
		}
	}
	else
	{
		return (this->pGameSprite->origHeight);
	}
}

const float GameObject2D::GetOrigAngle() const
{
	return this->pPhyObj->GetAngle();
}

void GameObject2D::SetOrigAngle(const float newAngle)
{
	this->pPhyObj->SetAngle(newAngle);
}

GameObject2D::~GameObject2D()
{
	// delete associated physics object.
	if (this->pPhyObj != nullptr)
	{
		PhysicsManager::Delete(this->pPhyObj);
	}
	
	delete this->pGameSprite;
	delete this->pDebugSprite;
}

void GameObject2D::WorldUpdate(float currentTime)
{
	AZUL_UNUSED_FLOAT(currentTime);

	// Goal: update the world matrix
	Matrix Scale(MatrixScaleType::SCALE, this->scaleX, this->scaleY, 1.0f);
	Matrix Rot(RotType::ROT_Z, this->currAngle + this->offsetAngle);
	Matrix Trans(MatrixTransType::TRANS, this->posX, this->posY, 0.0f);

	*this->pWorld = Scale * Rot * Trans;
}

void GameObject2D::Update(float currentTime)
{
	AZUL_UNUSED_FLOAT(currentTime);

	// Goal: update the world matrix
	this->WorldUpdate(currentTime);

	// push to graphics object
	if (this->getGraphicsObject() != 0)
	{
		this->getGraphicsObject()->SetWorld(*this->pWorld);
	}

	// Push to the collision object
	if (this->getGraphicsObject_Collision() != 0)
	{
		this->getGraphicsObject_Collision()->SetWorld(*this->pWorld);
	}
}

void GameObject2D::Draw()
{
	if (this->drawSprite && this->pGameSprite != nullptr)
	{
		this->pGameSprite->Render();
	}

	if (this->drawDebug && this->pDebugSprite != nullptr)
	{
		this->pDebugSprite->Render();
	}
}

GraphicsObject *GameObject2D::getGraphicsObject()
{
	return this->pGameSprite;
};

GraphicsObject *GameObject2D::getGraphicsObject_Collision()
{
	return this->pDebugSprite;
};

EnumBase::Name GameObject2D::getName()
{
	return (EnumBase::Name)this->name;
}

void GameObject2D::MarkForDelete()
{
	if (this->deleteMe == false)  // don't add to delete more than once!
	{
		this->deleteMe = true;
		GameObjectMan::AddToDeleteList(this);
	}
}


void GameObject2D::PhysicsUpdate(b2Vec2 posInMeters, float angleInRadians)
{
	// updates position and angle from physics update
	this->posX = MeterToPixel(posInMeters.x);
	this->posY = MeterToPixel(posInMeters.y);
	this->currAngle = angleInRadians;
}

void GameObject2D::SwapImage(GraphicsObject_Sprite* pSprite)
{
	GraphicsObject_Sprite* pTmp =  this->pGameSprite;
	this->pGameSprite = pSprite;
	delete pTmp;
}
