#include <string.h>

#include "ShaderNode.h"

ShaderNode::ShaderNode()
{
	pShader = new Shader();
};

ShaderNode::~ShaderNode()
{
	delete pShader;
}

void ShaderNode::SetShader(ShaderName::Name shaderName, const char * const shaderBaseFileName)
{
	pShader->Set(shaderName, shaderBaseFileName);
}

ShaderName::Name ShaderNode::GetShaderName() const
{
	return pShader->name;
}

Shader *ShaderNode::GetShader()
{
	return pShader;
}