#include <assert.h>

#include "Model.h"
#include "GraphicsObject_ColorByPosition.h"
#include "Camera.h"
#include "CameraMan.h"

GraphicsObject_ColorByPosition::GraphicsObject_ColorByPosition(Model *model, Shader *pShaderObj)
: GraphicsObject(model, pShaderObj)
{

}

void GraphicsObject_ColorByPosition::SetState()
{	
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void GraphicsObject_ColorByPosition::SetDataGPU()
{	     
	// Get camera
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);

	// set the vao
	glBindVertexArray(this->getModel()->vao);
	
	// use this shader
	this->pShaderObj->SetActive();

	Matrix world = this->getWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *)&view);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *)&world);
}

void GraphicsObject_ColorByPosition::Draw()
{	     
	// draw
	glDrawElements(GL_TRIANGLES, 3 * this->getModel()->numTris, GL_UNSIGNED_INT, 0);   //The starting point of the IBO
}

void GraphicsObject_ColorByPosition::RestoreState()
{	
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}