#include "TowerControl.h"
#include "Keyboard.h"
TowerControl::TowerControl(Tower* newTow)
	:
	buildState(BuildState::NOT_BUILT),
	pTow(newTow)
{
	pTow->Build();
}

TowerControl::~TowerControl()
{
	pTow->Destroy();
	delete pTow;
}


void TowerControl::Update()
{
	/*static bool homeKey = false;
	homeKey = Keyboard::GetKeyState(AZUL_KEY::KEY_F);
	if (homeKey && (buildState == BuildState::NOT_BUILT))
	{
		pTow->Build();
		buildState = BuildState::BUILT;
	}

	static bool delKey = false;
	delKey = Keyboard::GetKeyState(AZUL_KEY::KEY_G);
	if (delKey && (buildState == BuildState::BUILT))
	{
		pTow->Destroy();
		buildState = BuildState::NOT_BUILT;
	}*/
}
