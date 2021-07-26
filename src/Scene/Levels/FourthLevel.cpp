#include "FourthLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "InputManager.h"
#include "LineDynamicCollider.h"
#include "Egg.h"
#include "SceneManager.h"
#include "LoadLevel.h"
#include "Rope.h"
#include "Platform.h"
FourthLevel::FourthLevel()
	:
	pSys(nullptr),
	pEgg(nullptr),
	carBody(nullptr),
	pFrontWheel(nullptr),
	pRearWheel(nullptr),
	carSpeed(0.0f),
	newRope(nullptr),
	newRope2(nullptr),
	newPlat(nullptr),
	newPlat2(nullptr)
{
}

FourthLevel::~FourthLevel()
{
}

void FourthLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	// wood
	Rect rect = Rect(460.0f, 600.0f, 400.0f, 15.0f);
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
	rect = Rect(860.0f, 600.0f, 400.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	this->Add(tC);

	// Egg
	rect = Rect(700.0f, 650.0f, 25.0f, 40.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::Egg, rect, Rect(), true);
	pEgg = (Egg*)tC;
	this->Add(tC);

	// stone
	rect = Rect(500.0f, 700.0f, 10.0f, 15.0f);
	GameObject2D* emptyTop = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(emptyTop);

	// rope
	newRope = new Rope(b2Vec2(Game::GetWindowWidth() / 2.0f, 10.0f), emptyTop, 60);

	// stone
	rect = Rect(510.0f, 700.0f, 10.0f, 15.0f);
	emptyTop = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(emptyTop);

	// rope
	newRope2 = new Rope(b2Vec2(Game::GetWindowWidth() / 2.0f, 10.0f), emptyTop, 60);

	// Frame invinsibe
	rect = Rect(150.0f, 250.0f, 150.0f, 20.0f);
	GameObject2D* pFrame = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, rect, Rect(), true);
	this->Add(pFrame);

	// Moving Platform
	rect = Rect(150.0f, 250.0f, 200.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// create new platform.
	newPlat = new Platform(pFrame, tC, 0.0f, 7.0f, b2Vec2(0.0f, 1.0f));

	// wood
	rect = Rect(350.0f, 220.0f, 300.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);

	// wood
	rect = Rect(900.0f, 80.0f, 320.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(0.1f);
	this->Add(tC);

	// Frame invinsibe
	rect = Rect(1170.0f, 50.0f, 150.0f, 20.0f);
	pFrame = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, rect, Rect(), true);
	this->Add(pFrame);

	// Moving Platform
	rect = Rect(1170.0f, 50.0f, 200.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// create new platform.
	newPlat2 = new Platform(pFrame, tC, 0.0f, 12.0f, b2Vec2(0.0f, 1.0f));
}

void FourthLevel::Update()
{
	newPlat->ComputePlatformDistance();
	// pistoin control
	if (newPlat->GetPlatformDistance() < 0.1f)
	{
		newPlat->SetMotorSpeed(1);
		newPlat->SetMaxMotorForce(300);
	}
	else if (newPlat->GetPlatformDistance() > 45.0f)
	{
		newPlat->SetMotorSpeed(-1);
		newPlat->SetMaxMotorForce(300);
	}

	newPlat2->ComputePlatformDistance();
	// pistoin control
	if (newPlat2->GetPlatformDistance() < 0.1f)
	{
		newPlat2->SetMotorSpeed(1);
		newPlat2->SetMaxMotorForce(300);
	}
	else if (newPlat2->GetPlatformDistance() > 130.0f)
	{
		newPlat2->SetMotorSpeed(-1);
		newPlat2->SetMaxMotorForce(300);
	}

	CarControl();

	GameObjectMan::Update(0.0f);

	if (pEgg->nextLevel)
	{
		LoadLevel* loadLevel = (LoadLevel*)SceneManager::Find(Scene::Name::LOAD_LEVEL);
		loadLevel->sceneName = Scene::Name::FIRST_LEVEL;
		SceneManager::SetCurrentScene(Scene::Name::LOAD_LEVEL);
	}
}

void FourthLevel::Draw()
{
	GameObjectMan::Draw();

	// render line collider.
	pSys->Render();
}

void FourthLevel::Clean()
{
	delete newPlat;
	delete newPlat2;

	delete newRope;
	delete newRope2;
	PhysicsManager::DestroyAllJoints();
	InputManager::Delete(InputSystem::InputType::LINE_DYNAMIC_COLLIDER);
}

void FourthLevel::CreateCar()
{
	// car body
	Rect rect = Rect(400.0f, 650.0f, 60.0f, 30.0f);
	carBody = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	carBody->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(carBody);

	// rear wheel
	rect = Rect(350.0f, 625.0f, 30.0f, 30.0f);
	GameObject2D* rearWheel = ObjectFactory::CreateObject(GameObjectName::Name::Gear1, rect, Rect(), true);
	rearWheel->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(rearWheel);

	// front wheel
	rect = Rect(450.0f, 625.0f, 30.0f, 30.0f);
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

void FourthLevel::CarControl()
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
