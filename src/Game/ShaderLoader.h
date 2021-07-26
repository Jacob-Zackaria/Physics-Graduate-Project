#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include "ShaderMan.h"

void LoadShaders()
{
	ShaderMan::addShader(ShaderName::Name::SPRITE, "Shaders/spriteRender");
	ShaderMan::addShader(ShaderName::Name::SPRITE_LINE, "Shaders/spriteLineRender");
	ShaderMan::addShader(ShaderName::Name::SPRITE_TRI, "Shaders/spriteTriRender");
}

#endif