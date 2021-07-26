#ifndef GAME_OBJECT_CHARACTERISTICS
#define GAME_OBJECT_CHARACTERISTICS

#include "Animation.h"
class GameObjectCharacteristics
{
public:
	GameObjectCharacteristics::GameObjectCharacteristics()
		:
		newAnim(nullptr),
		health(0.0f),
		damagable(true),
		markedDead(false)
	{
	}
	GameObjectCharacteristics(const GameObjectCharacteristics&) = delete;
	const GameObjectCharacteristics& operator = (const GameObjectCharacteristics&) = delete;
	virtual GameObjectCharacteristics::~GameObjectCharacteristics() {}

	virtual void ReduceHealth(const float newVal) = 0;

	void SetDamagable(const bool newBool) { this->damagable = newBool; }


protected:
	Animation* newAnim;
	float health;
	bool damagable;
	bool markedDead;
};

#endif GAME_OBJECT_CHARACTERISTICS