#ifndef GAME_OBJECT_2D_H
#define GAME_OBJECT_2D_H

#include "MathEngine.h"
#include "GameObject.h"
#include "GraphicsObject_Sprite.h"
#include "GraphicsObject_Circle.h"
#include "GraphicsObject_Box.h"
#include "GraphicsObject_Tri.h"
#include "Box2D.h"
#include "CollisionControl.h"

// forward declaration
class PhysicsObject;

class GameObject2D : public GameObject, public CollisionControl
{
public:
	enum class DEBUG_SHAPE { Box, Circle, Triangle };

	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Tri* graphicsObject_Tri);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject, GraphicsObject_Box *graphicsObject_Box);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject, GraphicsObject_Circle *graphicsObject_Circle);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject, DEBUG_SHAPE _shape);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject);
	GameObject2D(GameObjectName::Name name);

	virtual ~GameObject2D() override;

	virtual void Update(float t) override;
	virtual void Draw() override;

	void PhysicsUpdate(b2Vec2 posInMeters, float angleInRadians);
	void SwapImage(GraphicsObject_Sprite* pSprite);

	virtual void WorldUpdate(float currentTime) override;
	virtual EnumBase::Name getName() override;
	virtual GraphicsObject *getGraphicsObject() override;
	virtual GraphicsObject *getGraphicsObject_Collision() override;

	void MarkForDelete();

private:
	GraphicsObject_Sprite *pGameSprite;
	GraphicsObject *pDebugSprite;
	DEBUG_SHAPE DebugShape;
	GameObjectName::Name name;

	bool drawSprite;
	bool drawDebug;

	// links
	GameObject2D* pNext;
	GameObject2D* pPrev;

	PhysicsObject* pPhyObj;

	void privBuilder(GameObjectName::Name name, GraphicsObject_Sprite *pgo, GraphicsObject *pgodebug, DEBUG_SHAPE sh);


protected:

	float scaleX;
	float scaleY;
	float posX;
	float posY;
	float currAngle;
	float offsetAngle;
	GameObjectName::Name sortBucket;
	
public: 
	const GameObjectName::Name GetBucketName() const;
	void SetBucketName(const GameObjectName::Name newName);
	const DEBUG_SHAPE GetDebugShape() const;

	GraphicsObject* GetGameSprite() { return pGameSprite; }
	void SetGameSprite(GraphicsObject_Sprite* s) { pGameSprite = s; }

	GraphicsObject* GetDebugSprite() { return pDebugSprite; }
	void SetDebugSprite(GraphicsObject* s) { pDebugSprite = s; }
	void SetDebugColor(Color::Type col);

	GameObjectName::Name GetName() { return name; }
	
	void SetDrawSprite(bool b) { drawSprite = b; }
	void SetDrawDebug(bool b) { drawDebug = b; }

	void SetScaleX(const float newScaleX) { scaleX = newScaleX; }
	void SetScaleY(const float newScaleY) { scaleY = newScaleY; }
	void SetScale(const float newScaleX, const float newScaleY);

	const float& GetScaleX() const { return scaleX; }
	const float& GetScaleY() const { return scaleY; }
	void GetScale(float& newScaleX, float& newScaleY);

	// if physics object exist, this also affect physics object.
	void SetPos(const float newPosX, const float newPosY);

	const float& GetPosX() const { return posX; }
	const float& GetPosY() const { return posY; }
	void GetPos(float& newPosX, float& newPosY);

	
	const float& GetCurrentAngle() const { return currAngle; }
	// if physics object doesnt exist change this angle.
	void SetCurrentAngle(const float newAngle) { currAngle = newAngle; }
	void SetOffsetAngle(const float newAngle) { offsetAngle = newAngle; }

	// Physics Control

	// multiple fixture control.
	void SetFixture(b2Fixture* newFix, const float newAngle, const float newPosX = 0.0f, const float newPosY = 0.0f);

	void SetBody(b2Body* b);
	b2Body* GetBody();

	b2Fixture* GetFixtureByIndex(const int i);

	const float& GetOriginalWidth() const;
	const float& GetOriginalHeight() const;

	const float GetOrigAngle() const;
	void SetOrigAngle(const float newAngle);

	void SetPhysicsObject(PhysicsObject* b) { this->pPhyObj = b; }
	PhysicsObject* GetPhysicsObject() { return this->pPhyObj; }

	//-----links----
	void GameObject2D::setNext(GameObject2D* newNext) { this->pNext = newNext; }
	void GameObject2D::setPrev(GameObject2D* newPrev) {	this->pPrev = newPrev; }

	GameObject2D* GameObject2D::getNext() const	{ return (this->pNext); }
	GameObject2D* GameObject2D::getPrev() const	{ return (this->pPrev);	}
};


#endif