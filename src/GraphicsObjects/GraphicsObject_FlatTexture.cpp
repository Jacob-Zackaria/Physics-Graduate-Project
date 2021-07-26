#include <assert.h>

#include "GraphicsObject_FlatTexture.h"
#include "TextureMan.h"
#include "Model.h"
#include "Camera.h"
#include "CameraMan.h"

GraphicsObject_FlatTexture::GraphicsObject_FlatTexture(Model *model, Shader *pShaderObj, TextName::Name name)
: GraphicsObject(model, pShaderObj), textName(name)
{
	
}

void GraphicsObject_FlatTexture::SetState()
{	
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture
	GLuint textureID = TextureMan::find( this->textName );
	glBindTexture(GL_TEXTURE_2D, textureID);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void GraphicsObject_FlatTexture::SetDataGPU()
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

void GraphicsObject_FlatTexture::Draw()
{	     
	// draw
	glDrawElements(GL_TRIANGLES, 3 * this->getModel()->numTris, GL_UNSIGNED_INT, 0);   //The starting point of the IBO
}

void GraphicsObject_FlatTexture::RestoreState()
{	     
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}
