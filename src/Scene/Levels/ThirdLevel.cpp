#include "ThirdLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "InputManager.h"
#include "LineDynamicCollider.h"
#include "Egg.h"
#include "SceneManager.h"
#include "LoadLevel.h"
#include "TimerMan.h"
#include "GravityBox.h"
#include "Platform.h"
ThirdLevel::ThirdLevel()
	:
	pSys(nullptr),
	pEgg(nullptr),
	carBody(nullptr),
	pFrontWheel(nullptr),
	pRearWheel(nullptr),
	carSpeed(0.0f),
	newPlat(nullptr),
	newPlat2(nullptr),
	newPlat3(nullptr),
	newPlat4(nullptr)
{
}

ThirdLevel::~ThirdLevel()
{
}

void ThirdLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	// wood
	Rect rect = Rect(100.0f, 345.0f, 150.0f, 15.0f);
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

	// Gravity box holder
	rect = Rect(700.0f, 300.0f, 50.0f, 5.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);

	// Gravity box holder
	rect = Rect(700.0f, 250.0f, 50.0f, 5.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	this->Add(tC);

	// Gravity box holder
	rect = Rect(680.0f, 275.0f, 50.0f, 5.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	this->Add(tC);

	// Gravity box holder
	rect = Rect(720.0f, 275.0f, 50.0f, 5.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	this->Add(tC);

	// Gravity box
	rect = Rect(700.0f, 300.0f, 10.0f, 10.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StoneSmallSquare0, rect, Rect(), true);
	tC->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(tC);

	// Add timer event for gravity.
	TimerMan::AddEvent(6.0f, new GravityBox(tC));


	// Platform
	rect = Rect(1200.0f, 150.0f, 150.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// Platform
	rect = Rect(420.0f, 400.0f, 600.0f, 10.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(-0.5f);
	this->Add(tC);

	// Platform
	rect = Rect(1200.0f, 500.0f, 150.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// Frame invinsibe
	rect = Rect(1200.0f, 250.0f, 150.0f, 20.0f);
	GameObject2D* pFrame = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, rect, Rect(), true);
	this->Add(pFrame);

	// Moving Platform
	rect = Rect(1200.0f, 250.0f, 200.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// create new platform.
	newPlat = new Platform(pFrame, tC, 0.0f, 5.0f, b2Vec2(-1.0f, 0.0f));

	// Egg platform
	rect = Rect(100.0f, 545.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	this->Add(tC);

	// Egg
	rect = Rect(100.0f, 580.0f, 25.0f, 40.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::Egg, rect, Rect(), true);
	pEgg = (Egg*)tC;
	this->Add(tC);


	// Frame invinsibe
	rect = Rect(100.0f, 650.0f, 150.0f, 20.0f);
	pFrame = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, rect, Rect(), true);
	this->Add(pFrame);

	// Moving Platform
	rect = Rect(100.0f, 650.0f, 200.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// create new platform.
	newPlat2 = new Platform(pFrame, tC, 0.0f, 5.0f, b2Vec2(1.0f, 0.0f));

	// Frame invinsibe
	rect = Rect(1150.0f, 650.0f, 250.0f, 20.0f);
	pFrame = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, rect, Rect(), true);
	this->Add(pFrame);

	// Moving Platform
	rect = Rect(1150.0f, 650.0f, 250.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// create new platform.
	newPlat3 = new Platform(pFrame, tC, 0.0f, 10.0f, b2Vec2(-1.0f, 0.0f));

	// Frame invinsibe
	rect = Rect(700.0f, 350.0f, 200.0f, 20.0f);
	pFrame = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, rect, Rect(), true);
	this->Add(pFrame);

	// Moving Platform
	rect = Rect(700.0f, 350.0f, 200.0f, 20.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	this->Add(tC);

	// create new platform.
	newPlat4 = new Platform(pFrame, tC, 0.0f, 5.0f, b2Vec2(0.0f, 1.0f));
}

void ThirdLevel::Update()
{
	newPlat->ComputePlatformDistance();
	// pistoin control
	if (newPlat->GetPlatformDistance() < 0.1f)
	{
		newPlat->SetMotorSpeed(1);
		newPlat->SetMaxMotorForce(300);
	}
	else if (newPlat->GetPlatformDistance() > 25.0f)
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
	else if (newPlat2->GetPlatformDistance() > 25.0f)
	{
		newPlat2->SetMotorSpeed(-1);
		newPlat2->SetMaxMotorForce(300);
	}

	newPlat3->ComputePlatformDistance();
	// pistoin control
	if (newPlat3->GetPlatformDistance() < 0.1f)
	{
		newPlat3->SetMotorSpeed(1);
		newPlat3->SetMaxMotorForce(300);
	}
	else if (newPlat3->GetPlatformDistance() > 95.0f)
	{
		newPlat3->SetMotorSpeed(-1);
		newPlat3->SetMaxMotorForce(300);
	}

	newPlat4->ComputePlatformDistance();
	// pistoin control
	if (newPlat4->GetPlatformDistance() < 0.1f)
	{
		newPlat4->SetMotorSpeed(0.5f);
		newPlat4->SetMaxMotorForce(300);
	}
	else if (newPlat4->GetPlatformDistance() > 10.0f)
	{
		newPlat4->SetMotorSpeed(-0.5f);
		newPlat4->SetMaxMotorForce(300);
	}


	CarControl();

	GameObjectMan::Update(0.0f);

	if (pEgg->nextLevel)
	{
		LoadLevel* loadLevel = (LoadLevel*)SceneManager::Find(Scene::Name::LOAD_LEVEL);
		loadLevel->sceneName = Scene::Name::FOURTH_LEVEL;
		SceneManager::SetCurrentScene(Scene::Name::LOAD_LEVEL);
	}
}

void ThirdLevel::Draw()
{
	GameObjectMan::Draw();

	// render line collider.
	pSys->Render();
}

void ThirdLevel::Clean()
{
	delete newPlat;
	delete newPlat2;
	delete newPlat3;
	delete newPlat4;

	PhysicsManager::DestroyAllJoints();
	TimerMan::ClearTimerEvents();
	InputManager::Delete(InputSystem::InputType::LINE_DYNAMIC_COLLIDER);
}

void ThirdLevel::CreateCar()
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

void ThirdLevel::CarControl()
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
