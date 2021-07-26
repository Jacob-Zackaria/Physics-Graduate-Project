#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include "GameObject2D.h"

class PhysicsObject
{
public:
	PhysicsObject(GameObject2D* newGameObject, b2BodyType newType);
	PhysicsObject(const PhysicsObject&) = delete;
	const PhysicsObject& operator = (const PhysicsObject&) = delete;
	~PhysicsObject();

	b2Fixture* GetFixture();
	b2Body* GetBody();
	void SetBody(b2Body* newBody);
	const float GetAngle() const;
	void SetAngle(const float newAngle);
	void SetPos(const float newPosX, const float newPosY);

	void CreateShapeAndFixture(GameObject2D* newGameObject, b2Vec2 newPos, float newAngle);
	GameObject2D* GetGameObject2D() const;
	GameObjectName::Name GetName();

	//void AddFixture();

	//-----links----
	void setNext(PhysicsObject* newNext);
	void setPrev(PhysicsObject* newPrev);
	PhysicsObject* getNext() const;
	PhysicsObject* getPrev() const;

private:
	
	GameObject2D* pG2D;
	b2Body* pBody;

	// links
	PhysicsObject* pNext;
	PhysicsObject* pPrev;

};

#endif