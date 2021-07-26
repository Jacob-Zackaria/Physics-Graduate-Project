#ifndef SHADER_NODE_H
#define SHADER_NODE_H

#include "Shaders.h"

class ShaderNodeLink
{
public:
	ShaderNodeLink()
	{
		this->next = 0;
		this->prev = 0;
	}
	~ShaderNodeLink()
	{
	}
	ShaderNodeLink *next;
	ShaderNodeLink *prev;
};


class ShaderNode : public ShaderNodeLink
{
public:
	ShaderNode();
	~ShaderNode();
	void SetShader(ShaderName::Name shaderName, const char * const shaderBaseFileName);
	ShaderName::Name GetShaderName() const;
	Shader *GetShader();

private:
	Shader *pShader;
};


#endif