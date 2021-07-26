#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "MathEngine.h"
#include "Shaders.h"
class Model;

class RenderMaterial
{
protected:
	virtual void SetState() = 0;
	virtual void SetDataGPU() = 0;	
	virtual void Draw() = 0;
	virtual void RestoreState() = 0;

};

class GraphicsObject: private RenderMaterial
{
public:
	GraphicsObject(Model *model, Shader *pShaderObj);
	virtual ~GraphicsObject();

	GraphicsObject() = delete;

	void Render();
	void SetWorld( Matrix &_world);

	Model *getModel() const;
	Matrix &getWorld();

protected:
	Model	*pModel;
	Matrix	*pWorld;
	Shader	*pShaderObj;
};

#endif