#include <sb6.h>
#include <sb6ktx.h>
#include <math.h>
#include <assert.h>

#include "DebugOut.h"
#include "MathEngine.h"
#include "Game.h"
#include "GameObjectMan.h"
#include "CameraMan.h"
#include "Color.h"
#include "Vect2D.h"
#include "ModelMan.h"
#include "AzulStopWatch.h"
#include "TimerMan.h"
#include "TextureLoader.h"
#include "ImageLoader.h"
#include "ShaderLoader.h"
#include "PhysicsManager.h"
#include "InputManager.h"
#include "PixelToMeter.h"
#include "AngryContactListener.h"
#include "BirdFactory.h"
#include "PigFactory.h"
#include "ObjectFactory.h"
#include "BackgroundFactory.h"
#include "TowerFactory.h"
#include "SlingFactory.h"
#include "EffectFactory.h"
#include "LevelSelector.h"
#include "AudioManager.h"
#include "SceneManager.h"
#include "Visualizer.h"

// Levels
#include "FirstLevel.h"
#include "SecondLevel.h"
#include "ThirdLevel.h"
#include "FourthLevel.h"
#include "FifthLevel.h"
#include "SixthLevel.h"
#include "SeventhLevel.h"
#include "EighthLevel.h"
#include "LoadLevel.h"

Game* Game::ptrInstance = nullptr;

AngryContactListener* pMyContactListener;

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char* windowName, const int Width, const int Height)
	:Engine(windowName, Width, Height),
	aspect(0.0f)
{
		ptrInstance = this;
		screenWidth = static_cast<float>(Width);
		screenHeight = static_cast<float>(Height);
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	// Initialize timer
	AzulStopWatch::initStopWatch();

	// Start timer
	stopWatch.tic();
	totalWatch.tic();

	//---------------------------------------------------------------------------------------------------------
	// Box2D setup
	//---------------------------------------------------------------------------------------------------------

	// scale: pixels per meter
	UnitScale::Create(50.0f);

	// Add world to physics manager
	// Gravity in Y direction
	b2Vec2 gravity(0.0, -10.0f);
	b2World* pWorld = new b2World(gravity);
	PhysicsManager::AddWorld(pWorld);

	// create and initialize contact listener
	pMyContactListener = new AngryContactListener();
	pWorld->SetContactListener(pMyContactListener);

	//// Inputs Creation
	InputSystem* pSystem = (InputSystem*)new LevelSelector();
	InputManager::AddInputs(pSystem, InputSystem::InputType::LEVEL_SELECTOR);
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	//---------------------------------------------------------------------------------------------------------
	// Setup the current 2D orthographic Camera
	//---------------------------------------------------------------------------------------------------------
	Camera *pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	// Holder for the current 2D  cameras
	CameraMan::SetCurrentCamera(pCam2D, Camera::Type::ORTHOGRAPHIC_2D);

	// initial settings.
	CameraMan::InitialCamera2DSetup();


	////---------------------------------------------------------------------------------------------------------
	//// Load up the managers
	////---------------------------------------------------------------------------------------------------------
	// Create/Load Shader 
	LoadShaders();

	// model
	ModelMan::Create();

	// Textures
	LoadTextures();
	// Images
	LoadImages();

	GameObjectMan::Create();

	

	////---------------------------------------------------------------------------------------------------------
	//// Sort buckets (AKA sprite layers)
	////---------------------------------------------------------------------------------------------------------

	//// Create Effect Bucket
	EffectFactory::CreateEffectBucket();

	// Create Sling Bucket
	SlingFactory::CreateSlingBucket1();

	// Create Bird Bucket
	BirdFactory::CreateBirdBucket();

	// Create Sling Bucket
	SlingFactory::CreateSlingBucket2();

	//// Create Pig Bucket
	PigFactory::CreatePigBucket();

	// Create Tower Bucket
	TowerFactory::CreateTowerBucket();

	//// Create Object Bucket
	ObjectFactory::CreateObjectBucket();

	//// Create Background Bucket
	BackgroundFactory::CreateBackgroundBucket();

	///Scene
	Scene* pLevel = (Scene*)new FirstLevel();
	SceneManager::Add(pLevel, Scene::Name::FIRST_LEVEL);
	pLevel = (Scene*)new SecondLevel();
	SceneManager::Add(pLevel, Scene::Name::SECOND_LEVEL);
	pLevel = (Scene*)new ThirdLevel();
	SceneManager::Add(pLevel, Scene::Name::THIRD_LEVEL);
	pLevel = (Scene*)new FourthLevel();
	SceneManager::Add(pLevel, Scene::Name::FOURTH_LEVEL);
	pLevel = (Scene*)new LoadLevel();
	SceneManager::Add(pLevel, Scene::Name::LOAD_LEVEL);
	SceneManager::SetCurrentScene(Scene::Name::FIRST_LEVEL);

	// Load Audio
	Audio* pBgm = new Audio("../../../../../reference/reference/Asset/angrybirds/audio/title_theme.mp3");
	AudioManager::Add(pBgm, Audio::Name::BACKGROUND, true, false);
	AudioManager::SetVolume(Audio::Name::BACKGROUND, 0.001f);

	pBgm = new Audio("../../../../../reference/reference/Asset/angrybirds/audio/pig_singing_7.wav");
	AudioManager::Add(pBgm, Audio::Name::PIG_SING_7);
	AudioManager::SetVolume(Audio::Name::PIG_SING_7, 0.002f);

	pBgm = new Audio("../../../../../reference/reference/Asset/angrybirds/audio/redbird_yell01.wav");
	AudioManager::Add(pBgm, Audio::Name::RED_BIRD_YELL);
	AudioManager::SetVolume(Audio::Name::RED_BIRD_YELL, 0.002f);

	
	////-------------------------------------------------------------------------

	// Debug Messages.
	DebugMsg::out("\n---- Simulation Control ----");
	DebugMsg::out("\n\nKey P : Pause On/off");
	DebugMsg::out("\nKey O : Slow-mo On/off");
	DebugMsg::out("\nKey I : Single Step");
	DebugMsg::out("\nKey N : Normal mode");
	DebugMsg::out("\n\n---- Line Construction ----");
	DebugMsg::out("\n\nLeft Mouse : Draw line");
	DebugMsg::out("\nRight Mouse : Delete line");
	DebugMsg::out("\n\n---- Car Control ----");
	DebugMsg::out("\n\nLeft arrow : Left direction");
	DebugMsg::out("\nRight arrow : Right direction");
	DebugMsg::out("\n\n---- Level Control ----");
	DebugMsg::out("\n\nHome Key : Reset Level");
	DebugMsg::out("\nKey 1 : Level 1 Tutotial, I guess!");
	DebugMsg::out("\nKey 2 : Level 2 Fun Ride!");
	DebugMsg::out("\nKey 3 : Level 3 Upside down (Kinda like the movie!)");
	DebugMsg::out("\nKey 4 : Level 4 Ropes? Hmm, I wonder why?");
	DebugMsg::out("\nKey 5 : Level 5 Portals (*_*) Wooho! (Coming Soon!)\n");
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
	currentTime;
	// Time update.
	//      Get the time that has passed.
	//      Feels backwards, but its not, need to see how much time has passed
	stopWatch.toc();
	stopWatch.tic();
	totalWatch.toc();
	TimerMan::Update();

	// Update cameras - make sure everything is consistent
	CameraMan::Update(Camera::Type::ORTHOGRAPHIC_2D);

	// -------------  Add your update below this line: ----------------------------
	

	//// Update Input Manager
	InputManager::Update();

	//scene
	SceneManager::Update();

	// Update Physics
	PhysicsManager::Update();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	//scene
	SceneManager::Draw();

	// display debug sprites.
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_LEFT_SHIFT))
	{
		Visualizer::Render();
	}
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	//// Delete factories
	SceneManager::Terminate();

	//// Engine clean-up
	InputManager::Terminate();
	AudioManager::Terminate();
	PhysicsManager::Terminate();
	CameraMan::Terminate();
	ModelMan::Terminate();
	ShaderMan::Terminate();
	TextureMan::Terminate();
	ImageMan::Terminate();

	GameObjectMan::Terminate();
	TimerMan::Terminate();
	Visualizer::Terminate();

	delete pMyContactListener;
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
	const GLfloat blue[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, blue);
	glClearBufferfv(GL_DEPTH, 0, &one);
}

float Game::GetFrameTime()
{
	return Instance().stopWatch.timeInSeconds();
}

float Game::GetTotalTime()
{
	return Instance().totalWatch.timeInSeconds();
}

Game::~Game()
{
}

void Game::Run(const char* windowName, const int Width, const int Height)
{
	ptrInstance = new Game(windowName, Width, Height);
	ptrInstance->run();
	delete ptrInstance;
}
