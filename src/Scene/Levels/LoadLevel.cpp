#include "LoadLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "TimerMan.h"
#include "LevelLoader.h"
LoadLevel::LoadLevel()
	:
	sceneName(Scene::Name::NOT_INITIALIZED)
{
}

LoadLevel::~LoadLevel()
{
}

void LoadLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	LevelLoader* newEvent = new LevelLoader(sceneName);

	// L
	Rect rect = Rect(100.0f, 345.0f, 150.0f, 15.0f);
	GameObject2D* tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// L
	rect = Rect(130.0f, 280.0f, 70.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// O
	rect = Rect(220.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// O
	rect = Rect(250.0f, 280.0f, 70.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// O
	rect = Rect(250.0f, 410.0f, 70.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// O
	rect = Rect(280.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// A
	rect = Rect(400.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(1.2f);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// A
	rect = Rect(450.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(-1.2f);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// A
	rect = Rect(430.0f, 345.0f, 50.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// D
	rect = Rect(550.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// D
	rect = Rect(580.0f, 310.0f, 110.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI4);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// D
	rect = Rect(580.0f, 390.0f, 110.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(-MATH_PI4);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// I
	rect = Rect(700.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// N
	rect = Rect(800.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// N
	rect = Rect(850.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(-MATH_PI4);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// N
	rect = Rect(900.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// G
	rect = Rect(1000.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// G
	rect = Rect(1050.0f, 420.0f, 100.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// G
	rect = Rect(1030.0f, 300.0f, 70.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI4);
	newEvent->AddObjects(tC);
	this->Add(tC);

	// G
	rect = Rect(1080.0f, 300.0f, 70.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(-MATH_PI4);
	newEvent->AddObjects(tC);
	this->Add(tC);

	TimerMan::AddEvent(2.0f, newEvent);
}

void LoadLevel::Update()
{
	GameObjectMan::Update(0.0f);
}

void LoadLevel::Draw()
{
	GameObjectMan::Draw();
}

void LoadLevel::Clean()
{
	
}
