#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include "Animation.h"

class AnimationManager 
{
	
public:
	AnimationManager(const AnimationManager&) = delete;
	const AnimationManager& operator = (const AnimationManager&) = delete;
	~AnimationManager();

	static void Add(Animation* pNewAnim, Animation::Name newName);
	static Animation* Find(const Animation::Name newName);
	static void Terminate();
private:
	AnimationManager();
	static AnimationManager* privGetInstance();

	void privAddToFront(Animation* node, Animation*& head);
	void privRemove(Animation* pNewData, Animation*& pHead);

	Animation* pList;
};


#endif ANIMATION_MANAGER_H