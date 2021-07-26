#include "PhysicsManager.h"
#include "Keyboard.h"
#include "PixelToMeter.h"
PhysicsManager::PhysicsManager()
	:
	pList(nullptr),
	pState(SimulationState::NORMAL),
	pWorld(nullptr),
	pDelJointList(nullptr)
{
}

PhysicsManager::~PhysicsManager()
{
	delete pWorld;
}

void PhysicsManager::AddWorld(b2World* newWorld)
{
	PhysicsManager::privGetInstance()->pWorld = newWorld;
}

PhysicsObject* PhysicsManager::CreatePhysicsObject(GameObject2D* newGameObject, b2BodyType newType)
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();

	PhysicsObject* pTmp = new PhysicsObject(newGameObject, newType);

	pMan->privAddToFront(pTmp, pMan->pList);

	return (pTmp);
}

PhysicsObject* PhysicsManager::Find(GameObjectName::Name newName)
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();

	PhysicsObject* pPhyObj = pMan->pList;

	while (pPhyObj != nullptr)
	{
		if (pPhyObj->GetName() == newName)
		{
			return (pPhyObj);
		}
	}

	return nullptr;
}

void PhysicsManager::Update()
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();

	// Phase 1: Physics Update - Step world----------------------------
	int velocityIterations = 8;
	int positionIterations = 3;
	
	pMan->privSimulateInput();

	pMan->pWorld->Step(pMan->privSimulateValue(), velocityIterations, positionIterations);

	// Phase 2: Update the associated GameObjectsd --------------------
	b2Body* pBody = pMan->pWorld->GetBodyList();
	while (pBody != 0) // Loop through all the bodies in the Box2D
	{
		b2Fixture* pFix = pBody->GetFixtureList();
		while (pFix != 0) // For each body, loop through all its fixtures
		{
			// For a given fixture, get the associated GameObject2D
			GameObject2D* pGObj = static_cast<GameObject2D*>(pFix->GetUserData());

			b2Vec2 fixCenter;
			if (pBody->IsActive())
			{
				fixCenter = pFix->GetAABB(0).GetCenter();
			}
			else
			{   // Must extract the center this way when body is inactive
				b2AABB tmpAABB;
				pFix->GetShape()->ComputeAABB(&tmpAABB, pBody->GetTransform(), 0);
				fixCenter = tmpAABB.GetCenter();
			}

			
			float ang = pBody->GetAngle();
			
			pGObj->PhysicsUpdate(fixCenter, ang);

			pFix = pFix->GetNext();
		}

		pBody = pBody->GetNext();
	}

	// destroy joints marked for deletion.
	pMan->ClearDeleteJoint();
}

void PhysicsManager::Delete(PhysicsObject* newPhyObj)
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();
	pMan->privRemove(newPhyObj, pMan->pList);

	newPhyObj->GetGameObject2D()->SetPhysicsObject(nullptr);
	delete newPhyObj;
}

b2World* PhysicsManager::GetWorld()
{
	return(PhysicsManager::privGetInstance()->pWorld);
}

void PhysicsManager::Terminate()
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();

	PhysicsObject* temp = pMan->pList;
	PhysicsObject* temp2;
	while (temp != nullptr)
	{
		temp2 = temp;
		temp = temp->getNext();
		pMan->Delete(temp2);
	}

	pMan->DestroyAllJoints();
}

void PhysicsManager::AddToDeleteJoint(b2Joint* newJoint)
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();

	JointDeletion* pNewJoint = new JointDeletion(newJoint);

	pMan->privAddToFront(pNewJoint, pMan->pDelJointList);
}

b2DistanceJoint* PhysicsManager::CreateDistanceJoint(GameObject2D* bodyA, GameObject2D* bodyB, const float newLength)
{
	b2DistanceJointDef djdef;
	djdef.Initialize(
		bodyA->GetBody(),
		bodyB->GetBody(),
		bodyA->GetBody()->GetWorldCenter(),		// given on world coord
		bodyB->GetBody()->GetWorldCenter()		// given on world coord
	);

	djdef.length = newLength;

	//djdef.frequencyHz = 1.0f;			// 'strength' of the spring. keep < 30 
	//djdef.dampingRatio = .15f;		// how quickly to stop the oscillations.

	return (b2DistanceJoint*)PhysicsManager::privGetInstance()->pWorld->CreateJoint(&djdef);
}

b2RevoluteJoint* PhysicsManager::CreateRevoluteJoint(GameObject2D* bodyA, GameObject2D* bodyB)
{
	// Revolute Joint
	b2RevoluteJointDef rjdef;  // https://en.wikipedia.org/wiki/Revolute_joint
	rjdef.Initialize(
		bodyA->GetBody(),
		bodyB->GetBody(),
		bodyA->GetBody()->GetWorldCenter() 
	);


	return (b2RevoluteJoint*)PhysicsManager::privGetInstance()->pWorld->CreateJoint(&rjdef);
}

void PhysicsManager::DestroyAllJoints()
{
	b2World* pNewWorld = PhysicsManager::privGetInstance()->pWorld;

	b2Joint* pJoint = pNewWorld->GetJointList();
	b2Joint* pNew = nullptr;
	while (pJoint != nullptr)
	{
		pNew = pJoint;
		pJoint = pJoint->GetNext();
		pNewWorld->DestroyJoint(pNew);
	}
}

PhysicsManager* PhysicsManager::privGetInstance()
{
	static PhysicsManager newPhysics;
	return &newPhysics;
}

void PhysicsManager::privAddToFront(PhysicsObject* node, PhysicsObject*& head)
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

void PhysicsManager::privRemove(PhysicsObject* pNewData, PhysicsObject*& pHead)
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

void PhysicsManager::privAddToFront(JointDeletion* node, JointDeletion*& head)
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

void PhysicsManager::privRemove(JointDeletion* pNewData, JointDeletion*& pHead)
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

void PhysicsManager::ClearDeleteJoint()
{
	JointDeletion* pNewJoint = this->pDelJointList;
	JointDeletion* pTmp = nullptr;

	while (pNewJoint != nullptr)
	{
		pTmp = pNewJoint;
		pNewJoint = pNewJoint->getNext();
		this->privRemove(pTmp, this->pDelJointList);
		this->pWorld->DestroyJoint(pTmp->GetJoint());
		delete pTmp;
	}
}

float PhysicsManager::privSimulateValue()
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();
	float timestep = 0.0f; 

	// adding some debug controls for the simulation speed
	if (pMan->pState == SimulationState::PAUSE)
	{
		timestep = 0.0f;
	}
	else if (pMan->pState == SimulationState::SLOW_MOTION)
	{
		timestep = 1.0f / 600.0f;
	}
	else if (pMan->pState == SimulationState::SINGLE_STEP)
	{
		timestep = 1.0f / 60.0f;
		pMan->pState = SimulationState::PAUSE;
	}
	else
	{
		timestep = 1.0f / 60.0f; // 60 fps. Box2D does not recommend tying this to framerate
	}

	return (timestep);
}

void PhysicsManager::privSimulateInput()
{
	PhysicsManager* pMan = PhysicsManager::privGetInstance();
	static bool pauseKey = false;
	static bool slowmoKey = false;
	static bool singlestepKey = false;
	static short prevSet = 0;

	// adding some debug controls for the simulation speed
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_P) && !pauseKey)
	{
		if (prevSet == 1)
		{
			pMan->pState = SimulationState::NORMAL;
			prevSet = 0;
		}
		else
		{
			pMan->pState = SimulationState::PAUSE;
			prevSet = 1;
		}
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_O) && !slowmoKey)
	{
		if (prevSet == 2)
		{
			pMan->pState = SimulationState::NORMAL;
			prevSet = 0;
		}
		else
		{
			pMan->pState = SimulationState::SLOW_MOTION;
			prevSet = 2;
		}
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_I) && !singlestepKey)
	{
		pMan->pState = SimulationState::SINGLE_STEP;
		prevSet = 1;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_N))
	{
		pMan->pState = SimulationState::NORMAL;
		prevSet = 0;
	}

	pauseKey = Keyboard::GetKeyState(AZUL_KEY::KEY_P);
	slowmoKey = Keyboard::GetKeyState(AZUL_KEY::KEY_O);
	singlestepKey = Keyboard::GetKeyState(AZUL_KEY::KEY_I);
}
