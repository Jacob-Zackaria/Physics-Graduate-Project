#include "Tower1.h"
#include "GameObjectMan.h"
#include "ObjectFactory.h"
#include "PigFactory.h"
#include "SceneManager.h"
Tower1::Tower1(const float newX, const float newY, const int height)
	:
	Tower(newX, newY, height)
{
}

Tower1::~Tower1()
{
}

void Tower1::Build()
{
	float stickHeight = 20.0f;
	float stickWidth = 75.0f;
	for (int i = 0; i < towHeight; i++)
	{
		if (i == 0)
		{
			// tower platform
			Rect newRect = Rect(baseX, baseY + 25.0f, 165.0f, 65.0f);
			GameObject2D* pObj = ObjectFactory::CreateObject(GameObjectName::Name::TowerPlatform, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);

			newRect = Rect(baseX - (0.5f * stickWidth), baseY + (0.5f * stickWidth) + (i * stickWidth) + 70.0f, stickWidth, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);	
			b2Fixture* editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetDensity(20.0f);
			editFixture->GetBody()->ResetMassData();

			// MinionPig0
			newRect = Rect(baseX + 5.0f, baseY + stickHeight + 65.0f, 35.0f, 35.0f);
			pObj = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetFriction(0.3f);
			editFixture->SetRestitution(0.80f);

			newRect = Rect(baseX, baseY + (i * stickWidth) + stickWidth + 70.0f, stickWidth + 15.0f, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetDensity(20.0f);
			editFixture->GetBody()->ResetMassData();

			newRect = Rect(baseX + (0.5f * stickWidth), baseY + (0.5f * stickWidth) + (i * stickWidth) + 65.0f, stickWidth, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::StonePlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetDensity(20.0f);
			editFixture->GetBody()->ResetMassData();

			newRect = Rect(baseX - (2.0f * stickWidth), baseY + (0.5f * stickWidth) + (i * stickWidth), stickWidth - 15.0f, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);

			newRect = Rect(baseX - (2.0f * stickWidth) + 30.0f, baseY + (0.5f * stickWidth) + (i * stickWidth) + 30.0f, stickWidth + 60.0f, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);

			newRect = Rect(baseX + (2.0f * stickWidth) - 30.0f, baseY + (0.5f * stickWidth) + (i * stickWidth) + 30.0f, stickWidth + 60.0f, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);

			newRect = Rect(baseX + (2.0f * stickWidth) + 40.0f, baseY + (0.5f * stickWidth) + (i * stickWidth), stickWidth - 15.0f, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);

			// KingPig0
			newRect = Rect(baseX + (2.0f * stickWidth), baseY + stickHeight, 65.0f, 65.0f);
			pObj = PigFactory::CreatePig(GameObjectName::Name::KingPig0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetFriction(0.3f);
			editFixture->SetRestitution(0.80f);
		}
		else
		{
			Rect newRect = Rect(baseX - (0.5f * stickWidth) - 45.0f, baseY + (0.5f * stickWidth) + (i * stickWidth) + 10.0f, stickWidth, stickHeight);
			GameObject2D* pObj = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);

			newRect = Rect(baseX - (0.5f * stickWidth), baseY + (0.5f * stickWidth) + (i * stickWidth) + 80.0f, stickWidth, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);

			// MinionPig0
			newRect = Rect(baseX + 5.0f, baseY + (i * stickWidth) + stickHeight + 75.0f, 35.0f, 35.0f);
			pObj = PigFactory::CreatePig(GameObjectName::Name::MinionPig0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			b2Fixture* editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetFriction(0.3f);
			editFixture->SetRestitution(0.80f);

			newRect = Rect(baseX, baseY + (i * stickWidth) + stickWidth + 85.0f, stickWidth + 15.0f, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);

			newRect = Rect(baseX + (0.5f * stickWidth), baseY + (0.5f * stickWidth) + (i * stickWidth) + 80.0f, stickWidth, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);

			newRect = Rect(baseX + (0.5f * stickWidth) + 45.0f, baseY + (0.5f * stickWidth) + (i * stickWidth) + 80.0f, stickWidth, stickHeight);
			pObj = ObjectFactory::CreateObject(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);
			SceneManager::AddSceneObject(SceneManager::GetCurrentScene(), pObj);
			pObj->GetBody()->SetType(b2BodyType::b2_dynamicBody);
			pObj->SetOrigAngle(MATH_PI2);
		}
		
	}
}

void Tower1::Destroy()
{
}
