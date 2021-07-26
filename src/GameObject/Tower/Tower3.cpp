#include "Tower3.h"
#include "GameObjectMan.h"
#include "TowerFactory.h"
Tower3::Tower3(const float newX, const float newY, const int height)
	:
	Tower(newX, newY, height)
{
}

Tower3::~Tower3()
{
}

void Tower3::Build()
{
	float stickHeight = 20.0f;
	float stickWidth = 75.0f;
	for (int i = 0; i < towHeight; i++)
	{
		if (i == 0)
		{
			// tower platform
			Rect newRect = Rect(baseX, baseY - 45.0f, 165.0f, 65.0f);
			GameObject2D* pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::TowerPlatform, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI);

			newRect = Rect(baseX - (0.5f * stickWidth), baseY - (0.5f * stickWidth) - (i * stickWidth) - 65.0f, stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::StonePlatform0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI2);	
			b2Fixture* editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetDensity(20.0f);
			editFixture->GetBody()->ResetMassData();

			// MinionPig0
			newRect = Rect(baseX + 5.0f, baseY - stickHeight - 65.0f, 35.0f, 35.0f);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::MinionPig0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetFriction(0.3f);
			editFixture->SetRestitution(0.80f);

			newRect = Rect(baseX, baseY - (i * stickWidth) - stickWidth - 70.0f, stickWidth + 15.0f, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::StonePlatform0, newRect, Rect(), true);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetDensity(20.0f);
			editFixture->GetBody()->ResetMassData();

			newRect = Rect(baseX + (0.5f * stickWidth), baseY - (0.5f * stickWidth) - (i * stickWidth) - 65.0f, stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::StonePlatform0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI2);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetDensity(20.0f);
			editFixture->GetBody()->ResetMassData();

			newRect = Rect(baseX - (2.0f * stickWidth), baseY - (0.5f * stickWidth) - (i * stickWidth), stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI2);

			newRect = Rect(baseX - (2.0f * stickWidth), baseY - (0.5f * stickWidth) - (i * stickWidth) - stickWidth, stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);
			
			// MinionPig0
			newRect = Rect(baseX - (2.0f * stickWidth) + 30.0f, baseY - stickHeight, 35.0f, 35.0f);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::MinionPig0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetFriction(0.3f);
			editFixture->SetRestitution(0.80f);

			newRect = Rect(baseX + (2.0f * stickWidth) + 40.0f, baseY - (0.5f * stickWidth) - (i * stickWidth), stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI2);

			newRect = Rect(baseX + (2.0f * stickWidth) + 40.0f, baseY - (0.5f * stickWidth) - (i * stickWidth) - stickWidth, stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::WoodPlatform0, newRect, Rect(), true);

			// KingPig0
			newRect = Rect(baseX + (2.0f * stickWidth), baseY - stickHeight, 65.0f, 65.0f);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::KingPig0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI);
			editFixture = pObj->GetBody()->GetFixtureList();
			editFixture->SetFriction(0.3f);
			editFixture->SetRestitution(0.80f);
		}
		else
		{
			Rect newRect = Rect(baseX - (0.5f * stickWidth), baseY - (0.5f * stickWidth) - (i * stickWidth) - 85.0f, stickWidth, stickHeight);
			GameObject2D* pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI2);

			newRect = Rect(baseX, baseY - (i * stickWidth) - stickWidth - 90.0f, stickWidth + 15.0f, stickHeight);
			TowerFactory::CreateTowerElement(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);

			newRect = Rect(baseX + (0.5f * stickWidth), baseY - (0.5f * stickWidth) - (i * stickWidth) - 85.0f, stickWidth, stickHeight);
			pObj = TowerFactory::CreateTowerElement(GameObjectName::Name::GlassPlatform0, newRect, Rect(), true);
			pObj->SetOrigAngle(MATH_PI2);
		}
		
	}
}

void Tower3::Destroy()
{
	GameObjectMan::DeleteSortBucket((GameSortBucket*)GameObjectMan::Find(GameObjectName::Name::TowerBucket));
}
