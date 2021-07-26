#ifndef SHADER_MAN_H
#define SHADER_MAN_H

#include "sb6.h"
#include "Shaders.h"
#include "ShaderNode.h"
#include "ShaderName.h"

// Singleton
class ShaderMan
{
public:
	static void addShader(ShaderName::Name shaderName, const char * const shaderBaseFileName);
	static void Terminate();
	static Shader *findShader(const ShaderName::Name _name);

private:  // methods

	static ShaderMan *privGetInstance();
	ShaderMan();
	~ShaderMan();

	// helper private methods
	void privAddToFront(ShaderNodeLink *node, ShaderNodeLink *&head);

private:  // add

	ShaderNodeLink *active;
};

#endif