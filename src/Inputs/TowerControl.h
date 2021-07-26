#ifndef TOWER_CONTROL_H
#define TOWER_CONTROL_H

#include "InputSystem.h"
#include "Tower.h"

class TowerControl : InputSystem
{
	enum class BuildState
	{
		BUILT,
		NOT_BUILT
	};
public:
	TowerControl(Tower* newTow);
	TowerControl(const TowerControl&) = delete;
	const TowerControl& operator = (const TowerControl&) = delete;
	virtual ~TowerControl();

	virtual void Update() override;
private:
	BuildState buildState;
	Tower* pTow;
};


#endif TOWER_CONTROL_H