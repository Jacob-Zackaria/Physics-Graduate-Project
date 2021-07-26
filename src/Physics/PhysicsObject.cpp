#include "PhysicsObject.h"
#include "PhysicsManager.h"
#include "PixelToMeter.h"
PhysicsObject::PhysicsObject(GameObject2D* newGameObject, b2BodyType newType)
	:
	pG2D(newGameObject),
	pBody(nullptr),
	pNext(nullptr),
	pPrev(nullptr)
{
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = newType; 
	GroundBoxDef.position.Set(PixelToMeter(newGameObject->GetPosX()), PixelToMeter(newGameObject->GetPosY()));
	GroundBoxDef.angle = 0.0f;

	// Body
	this->pBody = PhysicsManager::GetWorld()->CreateBody(&GroundBoxDef);  // Bodies manage their own fixtures

	// create shape and fixture.
	this->CreateShapeAndFixture(newGameObject, b2Vec2(0.0f,0.0f), 0.0f);

}

PhysicsObject::~PhysicsObject()
{
	// destory body (will delete associated fixtures too)
	PhysicsManager::GetWorld()->DestroyBody(this->pBody);
}

b2Fixture* PhysicsObject::GetFixture()
{
	return (pBody->GetFixtureList());
}

b2Body* PhysicsObject::GetBody()
{
	return (this->pBody);
}

void PhysicsObject::SetBody(b2Body* newBody)
{
	this->pBody = newBody;
}

const float PhysicsObject::GetAngle() const
{
	return (this->pBody->GetAngle());
}

void PhysicsObject::SetAngle(const float newAngle)
{
	this->pBody->SetTransform(this->pBody->GetPosition(), newAngle);
}

void PhysicsObject::SetPos(const float newPosX, const float newPosY)
{
	this->pBody->SetTransform(b2Vec2(PixelToMeter(newPosX), PixelToMeter(newPosY)), this->pBody->GetAngle());
}


//-----links----
void PhysicsObject::setNext(PhysicsObject* newNext)
{
	this->pNext = newNext;
}

void PhysicsObject::setPrev(PhysicsObject* newPrev)
{
	this->pPrev = newPrev;
}

PhysicsObject* PhysicsObject::getNext() const
{
	return (this->pNext);
}

PhysicsObject* PhysicsObject::getPrev() const
{
	return (this->pPrev);
}

void PhysicsObject::CreateShapeAndFixture(GameObject2D* newGameObject, b2Vec2 newPos, float newAngle)
{
	b2PolygonShape boxShape;
	b2CircleShape circleShape;

	// Shape
	switch (newGameObject->GetDebugShape())
	{
	case GameObject2D::DEBUG_SHAPE::Box:
		
		boxShape.SetAsBox(PixelToMeter(newGameObject->GetOriginalWidth() * 0.5f),
			PixelToMeter(newGameObject->GetOriginalHeight() * 0.5f),
			newPos,
			newAngle);

		// Create Fixture
		pBody->CreateFixture(&boxShape, 10.0f)->SetUserData(newGameObject);
		break;
	case GameObject2D::DEBUG_SHAPE::Circle:

		circleShape.m_p.Set(newPos.x,newPos.y);
		circleShape.m_radius = PixelToMeter(newGameObject->GetOriginalWidth() * 0.5f);

		// Create Fixture
		pBody->CreateFixture(&circleShape, 10.0f)->SetUserData(newGameObject);
		break;

	default:
		assert(false);
		break;
	}

	
}

GameObject2D* PhysicsObject::GetGameObject2D() const
{
	return this->pG2D;
}


GameObjectName::Name PhysicsObject::GetName()
{
	return ((GameObjectName::Name)this->pG2D->getName());
}
