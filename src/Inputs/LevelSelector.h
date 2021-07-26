#ifndef LEVEL_SELECTOR_H
#define LEVEL_SELECTOR_H

#include "InputSystem.h"

class LevelSelector : InputSystem
{
public:
	LevelSelector();
	LevelSelector(const LevelSelector&) = delete;
	const LevelSelector& operator = (const LevelSelector&) = delete;
	virtual ~LevelSelector();

	virtual void Update() override;
private:

};


#endif LEVEL_SELECTOR_H