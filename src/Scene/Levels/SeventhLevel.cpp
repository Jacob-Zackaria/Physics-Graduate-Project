#include "SeventhLevel.h"
#include "ObjectFactory.h"
#include "Game.h"
#include "SlingQueue.h"
#include "Keyboard.h"
#include "InputManager.h"
#include "LineCollider.h"
#include "SaltSalt.h"
#include "BackgroundFactory.h"
SeventhLevel::SeventhLevel()
{
}

SeventhLevel::~SeventhLevel()
{
}

LineCollider* pSys;
void SeventhLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	SlingQueue::Create(3, 210.0f, 300.0f);

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Background, rect);
	this->Add(tC);

	////test tri
	//Rect rect = Rect(400.0f, 500.0f, 60.0f, 60.0f);
	//GameObject2D* tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodIsoTriangle0, rect, Rect(), true);
	//this->Add(tC);

	// Empty Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, Game::GetWindowHeight() - 595.0f, Game::GetWindowWidth(), 200.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(tC);

	// wood
	rect = Rect(700.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	tC->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(tC);

	// wood
	rect = Rect(720.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	tC->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(tC);

	// wood
	rect = Rect(740.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	tC->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(tC);

	// wood
	rect = Rect(760.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetOrigAngle(MATH_PI2);
	tC->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(tC);

	InputSystem* newSys = (InputSystem*)new SaltSalt();
	InputManager::AddInputs(newSys, InputSystem::InputType::SALT_SALT);

	pSys = new LineCollider(Color::Type::Red);
	InputManager::AddInputs((InputSystem*)pSys, InputSystem::InputType::LINE_COLLIDER);
}

void SeventhLevel::Update()
{
	static bool rKey = false;

	if (!rKey && Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		SlingQueue::ReloadBirds(210.0f, 300.0f);
	}
	rKey = Keyboard::GetKeyState(AZUL_KEY::KEY_R);

	GameObjectMan::Update(0.0f);
}

void SeventhLevel::Draw()
{
	GameObjectMan::Draw();

	// render line collider.
	pSys->Render();
}

void SeventhLevel::Clean()
{
	SlingQueue::Terminate();

	InputManager::Delete(InputSystem::InputType::SALT_SALT);
	InputManager::Delete(InputSystem::InputType::LINE_COLLIDER);
}
