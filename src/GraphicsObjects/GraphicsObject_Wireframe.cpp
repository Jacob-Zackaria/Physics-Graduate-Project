#include <assert.h>

#include "Model.h"
#include "Camera.h"
#include "CameraMan.h"
#include "GraphicsObject_Wireframe.h"
#include "Shader.h"

GraphicsObject_Wireframe::GraphicsObject_Wireframe(Model *model, Shader *pShaderObj)
: GraphicsObject(model, pShaderObj)
{

}

void GraphicsObject_Wireframe::SetState()
{	
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void GraphicsObject_Wireframe::SetDataGPU()
{	     
	// Draw Me: -----------------------------------------

	// Get camera
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);

	// set the vao
	glBindVertexArray(this->getModel()->vao);
	
		// Set state
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDisable(GL_CULL_FACE);

	// use this shader
	this->pShaderObj->SetActive();

	Matrix world = this->getWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *)&proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *)&view);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *)&world);
}

void GraphicsObject_Wireframe::Draw( )
{	     
	// draw
	glDrawElements(GL_TRIANGLES, 3 * this->getModel()->numTris, GL_UNSIGNED_INT, 0);   //The starting point of the IBO
  
}

void GraphicsObject_Wireframe::RestoreState()
{	     
	// Restore state
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
