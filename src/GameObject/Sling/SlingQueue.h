#ifndef SLING_QUEUE_H
#define SLING_QUEUE_H

#include "SlingList.h"
#include "TrailCollection.h"

class SlingQueue
{
public:
	enum class SlingState
	{
		LOADED,
		EMPTY
	};

	
	SlingQueue(const SlingQueue&) = delete;
	const SlingQueue& operator = (const SlingQueue&) = delete;
	~SlingQueue();

	static void Create(uint8_t newLimit, float newBaseX, float newBaseY);
	static void Terminate();

	static void AddBird(GameObject2D* pBird);
	static void LoadNext();
	static GameObject2D* GetLoadedObject();
	static const SlingState GetSlingState();
	static uint8_t GetCurrentCount();
	static uint8_t GetBirdLimit();
	static void SetState(SlingState newState);
	static bool CheckExist(GameObject2D* newObj);
	static void ReloadBirds(float newBaseX, float newBaseY);
	static TrailCollection* GetTrailCollection();

private:
	SlingQueue();
	static SlingQueue* privGetInstance();
	void privAddToFront(SlingList* node, SlingList*& head);
	void privRemove(SlingList* pNewData, SlingList*& pHead);

	SlingState sState;
	SlingList* pBirdList;
	GameObject2D* currentLoaded;
	uint8_t birdLimit;
	uint8_t currentCount;
	b2Vec2 slingPos;

	// Trail
	TrailCollection* trailCollection;
};

#endif SLING_QUEUE_H