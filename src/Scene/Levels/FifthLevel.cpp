#include "FifthLevel.h"
#include "Game.h"
#include "Keyboard.h"
#include "InputManager.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "PigFactory.h"
#include "FilterCategory.h"
#include "SlingQueue.h"
FifthLevel::FifthLevel()
{
}

FifthLevel::~FifthLevel()
{
}

void FifthLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	SlingQueue::Create(2, 210.0f, 340.0f);

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Space3, rect);
	tC->SetCurrentAngle(MATH_PI);
	this->Add(tC);

	// Empty Ground Middle
	rect = Rect(555.0f, 165.0f, 350.0f, 50.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	// Empty Ground First
	rect = Rect(185.0f, 240.0f, 170.0f, 50.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	// Empty Ground Last
	rect = Rect(1000.0f, 190.0f, 380.0f, 50.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	// create ferris wheel
	this->CreateFerris();
}

void FifthLevel::Update()
{
	static bool rKey = false;

	if (!rKey && Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		SlingQueue::ReloadBirds(210.0f, 340.0f);
	}
	rKey = Keyboard::GetKeyState(AZUL_KEY::KEY_R);

	GameObjectMan::Update(0.0f);
}

void FifthLevel::Draw()
{
	GameObjectMan::Draw();
}

void FifthLevel::Clean()
{
	SlingQueue::Terminate();
	PhysicsManager::DestroyAllJoints();
}

void FifthLevel::CreateFerris()
{
	// Ferris holder
	Rect rect = Rect(700.0f, 340.0f, 300.0f, 10.0f);
	GameObject2D* pHolder = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	pHolder->SetOrigAngle(MATH_PI2);
	b2Filter newFilter;
	newFilter.categoryBits = FilterCategory::DONT_COLLIDE;
	pHolder->GetBody()->GetFixtureList()->SetFilterData(newFilter);
	this->Add(pHolder);

	for (uint8_t i = 0; i < 4; i++)
	{
		// Seesaw seat 1
		rect = Rect(550.0f, 490.0f, 70.0f, 10.0f);
		if (i == 1)
		{
			rect = Rect(595.0f, 385.0f, 70.0f, 10.0f);
		}
		else if (i == 2)
		{
			rect = Rect(595.0f, 595.0f, 70.0f, 10.0f);
		}
		else if (i == 3)
		{
			rect = Rect(700.0f, 640.0f, 70.0f, 10.0f);
		}
		GameObject2D* pSeat1 = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
		pSeat1->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		this->Add(pSeat1);

		// Seesaw seat 2
		rect = Rect(850.0f, 490.0f, 70.0f, 10.0f);
		if (i == 1)
		{
			rect = Rect(805.0f, 595.0f, 70.0f, 10.0f);
		}
		else if (i == 2)
		{
			rect = Rect(805.0f, 385.0f, 70.0f, 10.0f);
		}
		else if (i == 3)
		{
			rect = Rect(700.0f, 340.0f, 70.0f, 10.0f);
		}
		GameObject2D* pSeat2 = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
		pSeat2->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		this->Add(pSeat2);

		// Seesaw platform
		rect = Rect(700.0f, 490.0f, 300.0f, 10.0f);
		GameObject2D* pPlatform = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
		pPlatform->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		newFilter.categoryBits = FilterCategory::DONT_COLLIDE;
		pPlatform->GetBody()->GetFixtureList()->SetFilterData(newFilter);
		if (i == 1)
		{
			pPlatform->SetOrigAngle(MATH_PI4);
		}
		else if (i == 2)
		{
			pPlatform->SetOrigAngle(MATH_3PI4);
		}
		else if (i == 3)
		{
			pPlatform->SetOrigAngle(MATH_PI2);
		}
		this->Add(pPlatform);


		// Minion Pig 1
		rect = Rect(550.0f, 515.0f, 45.0f, 45.0f);
		if (i == 1)
		{
			rect = Rect(595.0f, 410.0f, 45.0f, 45.0f);
		}
		else if (i == 2)
		{
			rect = Rect(595.0f, 620.0f, 45.0f, 45.0f);
		}
		else if (i == 3)
		{
			rect = Rect(700.0f, 665.0f, 45.0f, 45.0f);
		}
		GameObject2D* pig1 = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, rect, Rect(), true);
		this->Add(pig1);

		// Minion Pig 2
		rect = Rect(850.0f, 515.0f, 45.0f, 45.0f);
		if (i == 1)
		{
			rect = Rect(805.0f, 620.0f, 45.0f, 45.0f);
		}
		else if (i == 2)
		{
			rect = Rect(805.0f, 410.0f, 45.0f, 45.0f);
		}
		else if (i == 3)
		{
			rect = Rect(700.0f, 365.0f, 45.0f, 45.0f);
		}
		GameObject2D* pig2 = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, rect, Rect(), true);
		this->Add(pig2);


		// Revolute Joint in platform center
		b2RevoluteJointDef rjdef;
		rjdef.Initialize(
			pHolder->GetBody(),
			pPlatform->GetBody(),
			pPlatform->GetBody()->GetWorldCenter() // should connect to holder, but this works too
		);
		rjdef.enableMotor = true;
		rjdef.motorSpeed = -0.2f;
		rjdef.maxMotorTorque = 200;
		b2Joint* mainRevolt = PhysicsManager::GetWorld()->CreateJoint(&rjdef);


		// Revolute Joint and gear joint in seats
		{
			// seat 1
			rjdef.Initialize(
				pPlatform->GetBody(),
				pSeat1->GetBody(),
				pSeat1->GetBody()->GetWorldCenter()
			);
			b2Joint* seat1Joint = PhysicsManager::GetWorld()->CreateJoint(&rjdef);

			// seat 2
			rjdef.Initialize(
				pPlatform->GetBody(),
				pSeat2->GetBody(),
				pSeat2->GetBody()->GetWorldCenter()
			);
			b2Joint* seat2Joint = PhysicsManager::GetWorld()->CreateJoint(&rjdef);

			//pig1
			b2RopeJointDef ropejdef;
			ropejdef.bodyA = pSeat1->GetBody();
			ropejdef.bodyB = pig1->GetBody();
			ropejdef.localAnchorA.Set(0.0f, 0.0f);
			ropejdef.localAnchorB.Set(0.0f, 0.0f);
			ropejdef.maxLength = 0.5f;
			ropejdef.collideConnected = true;
			PhysicsManager::GetWorld()->CreateJoint(&ropejdef);

			//pig2
			ropejdef.bodyA = pSeat2->GetBody();
			ropejdef.bodyB = pig2->GetBody();
			ropejdef.localAnchorA.Set(0.0f, 0.0f);
			ropejdef.localAnchorB.Set(0.0f, 0.0f);
			ropejdef.maxLength = 0.5f;
			ropejdef.collideConnected = true;
			PhysicsManager::GetWorld()->CreateJoint(&ropejdef);

			
			// gear joint
			b2GearJointDef gjdef;
			gjdef.bodyA = pPlatform->GetBody();
			gjdef.bodyB = pSeat1->GetBody();
			gjdef.joint1 = mainRevolt;
			gjdef.joint2 = seat1Joint;
			gjdef.ratio = 1.0f;
			PhysicsManager::GetWorld()->CreateJoint(&gjdef);

			// gear joint
			gjdef.bodyA = pPlatform->GetBody();
			gjdef.bodyB = pSeat2->GetBody();
			gjdef.joint1 = mainRevolt;
			gjdef.joint2 = seat2Joint;
			gjdef.ratio = 1.0f;
			PhysicsManager::GetWorld()->CreateJoint(&gjdef);
		}
	}
}

