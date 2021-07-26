#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include <sb6.h>

#include <math.h>
#include <vmath.h>
#include "MathEngine.h"
#include "AzulStopWatch.h"

class b2World;

class Game : public Engine
{
private:
	static Game* ptrInstance;

	Game() = delete;
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(const char* windowName, const int Width, const int Height);

	static Game& Instance()
	{
		assert(ptrInstance != nullptr);
		return *ptrInstance;
	}

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update(float currentTime);
	virtual void Draw();
	virtual void UnLoadContent();

	virtual void ClearBufferFunc();

	float			screenWidth;
	float			screenHeight;
	float           aspect;

	AzulStopWatch	stopWatch;
	AzulStopWatch	totalWatch;

	
public:
	static void Run(const char* windowName, const int Width, const int Height);

	static float GetFrameTime();
	static float GetTotalTime();

	static float GetWindowWidth() { return Instance().screenWidth; }
	static float GetWindowHeight() { return Instance().screenHeight; }

};

#endif