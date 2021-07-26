#include "EighthLevel.h"
#include "ObjectFactory.h"
#include "InputManager.h"
#include "RayCastQuery.h"
#include "Rope.h"
#include "Stone.h"
//#include "AABBQuery.h"
#include "BackgroundFactory.h"
#include "SlingQueue.h"
#include "Game.h"

Rope* newRope;
EighthLevel::EighthLevel()
{
}

EighthLevel::~EighthLevel()
{
}

void EighthLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	SlingQueue::Create(3, 210.0f, 300.0f);

	// Load Background
	Rect rect = Rect((Game::GetWindowWidth() / 2.0f), (Game::GetWindowHeight() / 2.0f), Game::GetWindowWidth(), Game::GetWindowHeight());
	GameObject2D* tC = BackgroundFactory::CreateBackground(GameObjectName::Name::Background, rect);
	this->Add(tC);

	// Empty Ground
	rect = Rect(Game::GetWindowWidth() / 2.0f, Game::GetWindowHeight() - 595.0f, Game::GetWindowWidth(), 200.0f);
	GameObject2D* emptyDown = ObjectFactory::CreateObject(GameObjectName::Name::CollisionObjectBox, Rect(), rect, true);
	this->Add(emptyDown);

	// Ground Top
	rect = Rect(Game::GetWindowWidth() / 2.0f, 690.0f, Game::GetWindowWidth(), 20.0f);
	GameObject2D* emptyTop = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, rect, Rect(), true);
	Stone* pNewStone = (Stone*)emptyTop;
	pNewStone->SetDamagable(false);
	this->Add(emptyTop);

	// rope
	newRope = new Rope(b2Vec2(Game::GetWindowWidth() / 2.0f, 390.0f), emptyTop, 15, true);

	// wood
	rect = Rect(700.0f, 345.0f, 150.0f, 15.0f);
	tC = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, rect, Rect(), true);
	tC->SetDrawDebug(true);
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

	

	InputSystem* pSys = (InputSystem*)new RayCastQuery();
	InputManager::AddInputs(pSys, InputSystem::InputType::RAY_CAST_QUERY);

	//InputSystem* pSys = (InputSystem*)new AABBQuery();
	//InputManager::AddInputs(pSys, InputSystem::InputType::AABB_QUERY);
}

void EighthLevel::Update()
{
	static bool rKey = false;

	if (!rKey && Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		SlingQueue::ReloadBirds(210.0f, 300.0f);
	}
	rKey = Keyboard::GetKeyState(AZUL_KEY::KEY_R);

	GameObjectMan::Update(0.0f);
}

void EighthLevel::Draw()
{
	GameObjectMan::Draw();
	newRope->Render();
}

void EighthLevel::Clean()
{
	delete newRope;
	InputManager::Delete(InputSystem::InputType::RAY_CAST_QUERY);

	SlingQueue::Terminate();
	//InputManager::Delete(InputSystem::InputType::AABB_QUERY);
}
