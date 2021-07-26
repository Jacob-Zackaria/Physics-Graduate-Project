#include "LanderInput.h"
#include "Keyboard.h"
#include "PixelToMeter.h"
#include "EffectFactory.h"

LanderInput::LanderInput(GameObject2D* newGameObject)
	:pGobj(newGameObject)
{
}

LanderInput::~LanderInput()
{
}

void LanderInput::Update()
{
	float Acceleration = 12;
	b2Body* pBody = this->pGobj->GetBody();
	pBody->SetAngularDamping(12.0f);
	pBody->SetGravityScale(0.5f);

	//--------------------------------------------------------
	static GameObject2D* tC2 = nullptr;
	static b2Fixture* flameDown = nullptr;
	static bool wPressed = false;
	static bool wcreated = false;
	wPressed = Keyboard::GetKeyState(AZUL_KEY::KEY_W);
	if (wPressed)
	{
		
		float ang = pBody->GetAngle() + MATH_PI2;
		b2Vec2 dir_normal(cosf(ang), sinf(ang));

		pBody->ApplyForceToCenter(pBody->GetMass() * Acceleration * dir_normal, true);

		// Create flame
		if (!wcreated)
		{
			Rect rect = Rect(200.0f, 665.0f, 20.0f, 10.0f);
			tC2 = EffectFactory::CreateEffect(GameObjectName::Name::Flame, rect, Rect(), false);
			//this->pGobj->GetPhysicsObject()->CreateShapeAndFixture(tC2);
			flameDown = this->pGobj->GetBody()->GetFixtureList();
			flameDown->SetDensity(1.0f);
			flameDown->SetSensor(true);
			tC2->SetFixture(flameDown, MATH_PI2, 0.0f, -45.0f);

			wcreated = true;
		}
	}
	else if (wcreated && !wPressed)
	{
		wcreated = false;
		pBody->DestroyFixture(flameDown);
		GameObjectMan::Delete(tC2);
	}
	//-------------------------------------------------------------------------
	static GameObject2D* tC3 = nullptr;
	static b2Fixture* flameRight = nullptr;
	static bool aPressed = false;
	static bool acreated = false;
	aPressed = Keyboard::GetKeyState(AZUL_KEY::KEY_A);
	if (aPressed)
	{
		float ang = pBody->GetAngle() + MATH_PI;
		b2Vec2 dir(cosf(ang), sinf(ang));

		b2Vec2 ForcePoint(-PixelToMeter(25), PixelToMeter(25));

		pBody->ApplyForce(
			pBody->GetMass() * 2 * dir,
			pBody->GetWorldPoint(ForcePoint),
			true);
		
		// Create flame
		if (!acreated)
		{
			Rect rect = Rect(200.0f, 665.0f, 20.0f, 10.0f);
			tC3 = EffectFactory::CreateEffect(GameObjectName::Name::Flame, rect, Rect(), false);
			//this->pGobj->GetPhysicsObject()->CreateShapeAndFixture(tC3);
			flameRight = this->pGobj->GetBody()->GetFixtureList();
			flameRight->SetDensity(1.0f);
			flameRight->SetSensor(true);
			tC3->SetFixture(flameRight, MATH_PI, 50.0f, 15.0f);

			acreated = true;
		}

	}
	else if (acreated && !aPressed)
	{
		acreated = false;
		pBody->DestroyFixture(flameRight);
		GameObjectMan::Delete(tC3);
	}
	//-----------------------------------------------------------

	static GameObject2D* tC4 = nullptr;
	static b2Fixture* flameLeft = nullptr;
	static bool dPressed = false;
	static bool dcreated = false;
	dPressed = Keyboard::GetKeyState(AZUL_KEY::KEY_D);
	if (dPressed)
	{
		float ang = pBody->GetAngle();
		b2Vec2 dir(cosf(ang), sinf(ang));

		b2Vec2 ForcePoint(PixelToMeter(25), PixelToMeter(25));

		pBody->ApplyForce(
			pBody->GetMass() * 2 * dir,
			pBody->GetWorldPoint(ForcePoint),
			true);
		
		// Create flame
		if (!dcreated)
		{
			Rect rect = Rect(200.0f, 665.0f, 20.0f, 10.0f);
			tC4 = EffectFactory::CreateEffect(GameObjectName::Name::Flame, rect, Rect(), false);
			//this->pGobj->GetPhysicsObject()->CreateShapeAndFixture(tC4);
			flameLeft = this->pGobj->GetBody()->GetFixtureList();
			flameLeft->SetDensity(1.0f);
			flameLeft->SetSensor(true);
			tC4->SetFixture(flameLeft, 0.0f, -50.0f, 15.0f);

			dcreated = true;
		}
	}
	else if (dcreated && !dPressed)
	{
		dcreated = false;
		pBody->DestroyFixture(flameLeft);
		GameObjectMan::Delete(tC4);
	}
}
