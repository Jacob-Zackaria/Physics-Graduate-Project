#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "MathEngine.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "GameObjectName.h"

class GameObject : public PCSNode
{
friend class GameObjectMan; // for deleteMa access

public:
	GameObject();
	virtual ~GameObject();

	virtual void WorldUpdate(float t) = 0;

	// Used in the Find function of GameObjectMan
	virtual EnumBase::Name getName() = 0;
	virtual void Update(float t) = 0;
	virtual void Draw() = 0;
	Matrix &getWorld();

	virtual GraphicsObject *getGraphicsObject() = 0;
	virtual GraphicsObject *getGraphicsObject_Collision() = 0;

	bool ManagedNoDelete;
	virtual void ManagedSceneExit() {};

protected:
	Matrix	*pWorld;
	bool deleteMe;

private:
	// prevent from calling
	GameObject(GameObject &copy);

};


#endif