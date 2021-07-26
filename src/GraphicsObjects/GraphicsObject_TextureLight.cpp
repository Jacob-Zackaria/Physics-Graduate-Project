#include <assert.h>

#include "GraphicsObject_TextureLight.h"
#include "Model.h"
#include "TextureMan.h"
#include "Camera.h"
#include "CameraMan.h"

GraphicsObject_TextureLight::GraphicsObject_TextureLight(Model *model, Shader *pShaderObj, TextName::Name name, Vect &LightColor, Vect &LightPos)
: GraphicsObject(model, pShaderObj), 
textName(name)
{
	this->pLightColor = new Vect(LightColor);
	this->pLightPos = new Vect(LightPos);
}

GraphicsObject_TextureLight::~GraphicsObject_TextureLight()
{
	delete this->pLightColor;
	delete this->pLightPos;
}

void GraphicsObject_TextureLight::SetState()
{	
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture
	GLuint textureID = TextureMan::find( this->textName );
	glBindTexture(GL_TEXTURE_2D, textureID);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}

void GraphicsObject_TextureLight::SetDataGPU()
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

	glUniform3fv(this->pShaderObj->GetLocation("vLightPos"), 1, (float *)this->pLightPos);
	glUniform4fv(this->pShaderObj->GetLocation("vColor"), 1, (float *)this->pLightColor);
}


void GraphicsObject_TextureLight::Draw( )
{	     
	//The draw triangles by index
	glDrawElements(GL_TRIANGLES, 3 * this->getModel()->numTris, GL_UNSIGNED_INT, 0);   //The starting point of the IBO
}

void GraphicsObject_TextureLight::RestoreState( )
{	     
	// undo the states you corrupted
	glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
}
