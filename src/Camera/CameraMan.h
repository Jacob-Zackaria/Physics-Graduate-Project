#ifndef CAMERA_MAN_H
#define CAMERA_MAN_H

#include "Camera.h"
#include "GameObject2D.h"
class CameraMan
{
private:
	static CameraMan *privInstance();
	CameraMan();
	~CameraMan();	

	// Data
	static CameraMan* ptrInstance;
	Camera *pCamOrthographic;
	Camera *pCamPerspective;

public:
	static Camera *GetCurrent(Camera::Type type);
	static void SetCurrentCamera(Camera *camera, Camera::Type type);
	static void Update(Camera::Type type);

	static void Terminate() { delete ptrInstance; }

	// cam control
	static void CamControl(GameObject2D* pGobj, b2Vec2 pad, float minZoom = 0.3f, float maxZoom = 1.0f, float edgeFactor = 1.5f);
	static void InitialCamera2DSetup();

};

#endif