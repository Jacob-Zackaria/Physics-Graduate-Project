#include "SixthLevel.h"
#include "Game.h"
#include "ObjectFactory.h"
#include "Keyboard.h"
#include "CameraMan.h"
SixthLevel::SixthLevel()
	:
	pTerrain(nullptr),
	carBody(nullptr),
	pFrontWheel(nullptr),
	pRearWheel(nullptr),
	carSpeed(0.0f)
{
}

SixthLevel::~SixthLevel()
{
}

void SixthLevel::AddSceneElements()
{
	PhysicsManager::GetWorld()->SetGravity(b2Vec2(0.0, -10.0f));

	srand((unsigned int)GetTickCount64());

	// generate terrain.
	pTerrain = new Terrain(b2Vec2(-200, 300), b2Vec2(Game::GetWindowWidth() + 200.0f, 300.0f), .05f, 70);

	// car body
	Rect rect = Rect(400.0f, 500.0f, 60.0f, 30.0f);
	carBody = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, rect, Rect(), true);
	carBody->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(carBody);

	// rear wheel
	rect = Rect(350.0f, 475.0f, 30.0f, 30.0f);
	GameObject2D* rearWheel = ObjectFactory::CreateObject(GameObjectName::Name::Gear1, rect, Rect(), true);
	rearWheel->GetBody()->SetType(b2BodyType::b2_dynamicBody);
	this->Add(rearWheel);

	// front wheel
	rect = Rect(450.0f, 475.0f, 30.0f, 30.0f);
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

void SixthLevel::Update()
{
	CameraMan::CamControl(carBody, b2Vec2(0.0f, 0.0f));

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

	GameObjectMan::Update(0.0f);
}

void SixthLevel::Draw()
{
	GameObjectMan::Draw();
}

void SixthLevel::Clean()
{
	delete pTerrain;
	PhysicsManager::DestroyAllJoints();
	CameraMan::InitialCamera2DSetup();
}
