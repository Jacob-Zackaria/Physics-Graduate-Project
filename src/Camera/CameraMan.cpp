#include <assert.h>
#include "CameraMan.h"
#include "Game.h"

CameraMan* CameraMan::ptrInstance = nullptr;

void CameraMan::SetCurrentCamera(Camera *camera, Camera::Type type)
{
	assert( camera != 0 );
	CameraMan *pCamMan = CameraMan::privInstance();
	switch (type)
	{
	case Camera::Type::PERSPECTIVE_3D:
		assert( camera->getType() == Camera::Type::PERSPECTIVE_3D );
		pCamMan->pCamPerspective = camera;
		break;

	case Camera::Type::ORTHOGRAPHIC_2D:
		assert( camera->getType() == Camera::Type::ORTHOGRAPHIC_2D );
		pCamMan->pCamOrthographic = camera;
		break;

	default:
		assert(false);
		break;
	}
	
}

Camera * CameraMan::GetCurrent(Camera::Type type)
{
	Camera *pCam = 0;
	switch (type)
	{
	case Camera::Type::PERSPECTIVE_3D:
		pCam = CameraMan::privInstance()->pCamPerspective;
		break;

	case Camera::Type::ORTHOGRAPHIC_2D:
		pCam = CameraMan::privInstance()->pCamOrthographic;
		break;

	default:
		assert(false);
		break;
	}
	
	assert( pCam != 0 );
	return pCam;
}

void CameraMan::Update(Camera::Type type)
{
	CameraMan* pCamMan = CameraMan::privInstance();

	switch (type)
	{
	case Camera::Type::PERSPECTIVE_3D:
		pCamMan->pCamPerspective->updateCamera();
		break;

	case Camera::Type::ORTHOGRAPHIC_2D:
		pCamMan->pCamOrthographic->updateCamera();
		break;

	default:
		assert(false);
		break;
	}
}

void CameraMan::CamControl(GameObject2D* pGobj, b2Vec2 pad, float minZoom, float maxZoom, float edgeFactor)
{
	maxZoom;
	Camera* pCam = CameraMan::privInstance()->pCamOrthographic;

	float screenwidth = (float)pCam->getScreenWidth();
	float screenheight = (float)pCam->getScreenHeight();
	float aspectRatio = screenwidth / screenheight;

	b2Vec2 objPos(pGobj->GetPosX(), pGobj->GetPosY());
	b2Vec2 extentVect = (objPos - pad);

	float width = fabs(extentVect.x);
	float height = fabs(extentVect.y);

	// clamp to minimum zoom-in 
	if (width < minZoom * (float)pCam->getScreenWidth()) width = minZoom * (float)pCam->getScreenWidth();
	if (height < minZoom * (float)pCam->getScreenHeight()) height = minZoom * (float)pCam->getScreenHeight();

	// Which axis is the dominant one (depends on relative position)
	if (width > height * aspectRatio)  // wide shot: adjust height based on width
	{
		height = width / aspectRatio;
	}
	else // tall view: adjust width to match required height
	{
		width = height * aspectRatio;
	}

	width *= edgeFactor;
	height *= edgeFactor;

	// Set the new width and height for the camera
	pCam->setOrthographic(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, 1.0f, 1000.0f);
	//pCam->setOrthographic(0, width, 0, height, 1.0f, 1000.0f);

	// Where to look
	b2Vec2 midpoint = .5f * (objPos + pad);
	Vect up(0, 1, 0);
	Vect lookat(midpoint.x - screenwidth / 2, midpoint.y - screenheight / 2, -1.0f);
	Vect pos(midpoint.x - screenwidth / 2, midpoint.y - screenheight / 2, 0.0f);

	pCam->setOrientAndPosition(up, lookat, pos);
}

void CameraMan::InitialCamera2DSetup()
{
	Camera* mCam = CameraMan::privInstance()->pCamOrthographic;

	mCam->setViewport(0, 0, (int)Game::GetWindowWidth(), (int)Game::GetWindowHeight());
	float halfwidth = Game::GetWindowWidth() / 2.0f;
	float halfheight = Game::GetWindowHeight() / 2.0f;
	mCam->setOrthographic(-halfwidth, halfwidth, -halfheight, halfheight, 1.0f, 1000.0f);
	mCam->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, -1.0f), Vect(0.0f, 0.0f, 0.0f));
}



CameraMan* CameraMan::privInstance()
{
	if (ptrInstance == nullptr)
		ptrInstance = new CameraMan();
	return ptrInstance;
}

CameraMan::CameraMan()
{
	this->pCamPerspective = 0;
	this->pCamOrthographic = 0;
}

CameraMan::~CameraMan()
{
	delete this->pCamPerspective;
	delete this->pCamOrthographic;
}