#include <assert.h>

#include "sb6.h"
#include "Game.h"


int CALLBACK WinMain(_In_ HINSTANCE , _In_opt_ HINSTANCE , _In_ LPSTR , _In_ int)
{
	Game::Run("Angry Birds", 1280, 720);
	return 0;
}

