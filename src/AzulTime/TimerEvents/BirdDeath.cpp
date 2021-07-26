#include "BirdDeath.h"
#include "SceneManager.h"
#include "TimerMan.h"
#include "SmokeDeletion.h"
#include "EffectFactory.h"
BirdDeath::BirdDeath(GameObject2D* pNewObj)
	:
	pObj(pNewObj)
{
}

void BirdDeath::Execute(float currTime)
{
	currTime;
	Rect rect = Rect(pObj->GetPosX(), pObj->GetPosY(), 35.0f, 35.0f);
	SmokeDeletion* newEvent = new SmokeDeletion(EffectFactory::CreateEffect(GameObjectName::Name::Smoke, rect));
	TimerMan::AddEvent(0.1f, newEvent);
	SceneManager::DeleteSceneObject(SceneManager::GetCurrentScene(), pObj);
}

BirdDeath::~BirdDeath()
{
}
