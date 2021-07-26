#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include "PhysicsObject.h"
#include "JointDeletion.h"

class PhysicsManager
{
public:
	enum class SimulationState
	{
		PAUSE,
		SLOW_MOTION,
		SINGLE_STEP,
		NORMAL
	};

	PhysicsManager(const PhysicsManager&) = delete;
	const PhysicsManager& operator = (const PhysicsManager&) = delete;
	~PhysicsManager();
	static void AddWorld(b2World* newWorld);
	static PhysicsObject* CreatePhysicsObject(GameObject2D* newGameObject, b2BodyType newType);
	static PhysicsObject* Find(GameObjectName::Name newName);
	static void Update();
	static void Delete(PhysicsObject* newPhyObj);
	static b2World* GetWorld();
	static void Terminate();
	static void AddToDeleteJoint(b2Joint* newJoint);

	// joints
	static b2DistanceJoint* CreateDistanceJoint(GameObject2D* bodyA, GameObject2D* bodyB, const float newLength = 2.0f);
	static b2RevoluteJoint* CreateRevoluteJoint(GameObject2D* bodyA, GameObject2D* bodyB);
	static void DestroyAllJoints();

private:
	static PhysicsManager* privGetInstance();
	PhysicsManager();

	void privAddToFront(PhysicsObject* node, PhysicsObject*& head);
	void privRemove(PhysicsObject* pNewData, PhysicsObject*& pHead);
	void privAddToFront(JointDeletion* node, JointDeletion*& head);
	void privRemove(JointDeletion* pNewData, JointDeletion*& pHead);
	void ClearDeleteJoint();
	float privSimulateValue();
	void privSimulateInput();

	PhysicsObject* pList;
	SimulationState pState;
	b2World* pWorld;
	JointDeletion* pDelJointList;
};

#endif