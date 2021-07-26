#include "SecondLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "InputManager.h"
#include "LineDynamicCollider.h"
#include "Egg.h"
#include "SceneManager.h"
#include "LoadLevel.h"
#include "FilterCategory.h"
SecondLevel::SecondLevel()
	:
	pSys(nullptr),
	pEgg(nullptr),
	carBody(nullptr),
	pFrontWheel(nullptr),
	pRearWheel(nullptr),
	carSpeed(0.0f)
{
}

SecondLevel::~SecondLevel()
{
	
}


void SecondLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	// wood
	Rect rect = Rect(150.0f, 245.0f, 450.0f, 15.0f);
	GameObject2D* tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);

	// Load Background
	rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Space4, rect);
	this->Add(tC);

	// Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, Game::GetWindowHeight() - 700.0f, Game::GetWindowWidth() + 20.0f, 50.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);


	// create car
	CreateCar();

	// line dynamic collider.
	pSys = new LineDynamicCollider(Color::Type::Red);
	InputManager::AddInputs((InputSystem*)pSys, InputSystem::InputType::LINE_DYNAMIC_COLLIDER);

	// Egg platform
	rect = Rect(1150.0f, 245.0f, 250.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	this->Add(tC);

	// Egg
	rect = Rect(1200.0f, 280.0f, 25.0f, 40.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::Egg, rect, Rect(), true);
	pEgg = (Egg*)tC;
	this->Add(tC);

	CreateFerris(700.0f, 180.0f);
	
}

void SecondLevel::Update()
{
	CarControl();

	GameObjectMan::Update(0.0f);

	if (pEgg->nextLevel)
	{
		LoadLevel* loadLevel = (LoadLevel*)SceneManager::Find(Scene::Name::LOAD_LEVEL);
		loadLevel->sceneName = Scene::Name::THIRD_LEVEL;
		SceneManager::SetCurrentScene(Scene::Name::LOAD_LEVEL);
	}
}

void SecondLevel::Draw()
{
	GameObjectMan::Draw();

	// render line collider.
	pSys->Render();
}

void SecondLevel::Clean()
{
	PhysicsManager::DestroyAllJoints();
	InputManager::Delete(InputSystem::InputType::LINE_DYNAMIC_COLLIDER);
}


void SecondLevel::CreateCar()
{
	// car body
	Rect rect = Rect(100.0f, 500.0f, 60.0f, 30.0f);
	carBody = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	carBody->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(carBody);

	// rear wheel
	rect = Rect(50.0f, 475.0f, 30.0f, 30.0f);
	GameObject2D* rearWheel = ObjectFactory::CreateObject(GameObjectName::Name::Gear1, rect, Rect(), true);
	rearWheel->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(rearWheel);

	// front wheel
	rect = Rect(150.0f, 475.0f, 30.0f, 30.0f);
	GameObject2D* frontWheel = ObjectFactory::CreateObject(GameObjectName::Name::Gear1, rect, Rect(), true);
	frontWheel->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(frontWheel);

	b2WheelJointDef rjdef;
	rjdef.Initialize(carBody->GetBody(), rearWheel->GetBody(), rearWheel->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	rjdef.frequencyHz = 5;
	rjdef.dampingRatio = .19f;
	pRearWheel = (b2WheelJoint*)PhysicsManager::GetWorld()->CreateJoint(&rjdef);

	rjdef.Initialize(carBody->GetBody(), frontWheel->GetBody(), frontWheel->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	rjdef.enableMotor = true;
	pFrontWheel = (b2WheelJoint*)PhysicsManager::GetWorld()->CreateJoint(&rjdef);

}

void SecondLevel::CarControl()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		if (carSpeed > -10.0f)
		{
			carSpeed -= 1.0f;
		}
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		if (carSpeed < 10.0f)
		{
			carSpeed += 1.0f;
		}
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		carSpeed = 0.0f;
	}
	else
	{
		carSpeed *= 0.95f;
	}

	pFrontWheel->SetMotorSpeed(carSpeed);
	pRearWheel->SetMotorSpeed(carSpeed);
}

void SecondLevel::CreateFerris(const float baseX, const float baseY)
{
	// Ferris holder
	Rect rect = Rect(baseX, baseY, 300.0f, 10.0f);
	GameObject2D* pHolder = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	pHolder->SetOrigAngle(MATH_PI2);
	b2Filter newFilter;
	newFilter.categoryBits = FilterCategory::DONT_COLLIDE;
	pHolder->GetBody()->GetFixtureList()->SetFilterData(newFilter);
	this->Add(pHolder);

	for (uint8_t i = 0; i < 2; i++)
	{
		// Seesaw seat 1
		rect = Rect(baseX - 200.0f, baseY + 150.0f, 250.0f, 10.0f);
		if (i == 1)
		{
			rect = Rect(baseX, baseY + 350.0f, 250.0f, 10.0f);
		}
		GameObject2D* pSeat1 = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
		pSeat1->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		this->Add(pSeat1);

		// Seesaw seat 2
		rect = Rect(baseX + 200.0f, baseY + 150.0f, 250.0f, 10.0f);
		if (i == 1)
		{
			rect = Rect(baseX, baseY - 50.0f, 250.0f, 10.0f);
		}
		GameObject2D* pSeat2 = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
		pSeat2->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		this->Add(pSeat2);

		// Seesaw platform
		rect = Rect(baseX, baseY + 150.0f, 400.0f, 10.0f);
		GameObject2D* pPlatform = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
		pPlatform->GetBody()->SetType(b2BodyType::b2_dynamicBody);
		newFilter.categoryBits = FilterCategory::DONT_COLLIDE;
		pPlatform->GetBody()->GetFixtureList()->SetFilterData(newFilter);
		if (i == 1)
		{
			pPlatform->SetOrigAngle(MATH_PI2);
		}
		this->Add(pPlatform);


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
