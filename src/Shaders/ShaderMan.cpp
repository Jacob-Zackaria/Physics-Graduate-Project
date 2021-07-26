#include <stdlib.h>
#include <sb6.h>
#include <assert.h>

#include "ShaderNode.h"
#include "ShaderMan.h"

ShaderMan::ShaderMan()
{
	this->active = 0;
}

ShaderMan * ShaderMan::privGetInstance()
{
	// This is where its actually stored (BSS section)
	static ShaderMan shaderMan;
	return &shaderMan;
}

void ShaderMan::addShader(ShaderName::Name shaderName, const char * const shaderBaseFileName)
{
	// Get the instance to the manager
	ShaderMan *pShaderMan = ShaderMan::privGetInstance();

	// Create a TextureNode
	ShaderNode *pNode = new ShaderNode();

	// initialize it
	pNode->SetShader(shaderName, shaderBaseFileName);

	// Now add it to the manager
	pShaderMan->privAddToFront(pNode, pShaderMan->active);
}


Shader *ShaderMan::findShader(const ShaderName::Name _name)
{
	// Get the instance to the manager
	ShaderMan *pShaderMan = ShaderMan::privGetInstance();
	ShaderNode *pNode = (ShaderNode *)pShaderMan->active;
	while (pNode != 0)
	{
		if (pNode->GetShaderName() == _name)
		{
			// found it
			break;
		}
		pNode = (ShaderNode *)pNode->next;
	}
	return pNode->GetShader();
}

ShaderMan::~ShaderMan()
{
	// to do
}

void ShaderMan::Terminate()
{
	// Get the instance to the manager
	ShaderMan *pShedMan = ShaderMan::privGetInstance();
	ShaderNode *pNode = (ShaderNode*)pShedMan->active;
	while (pNode != 0)
	{
		// bye bye
		ShaderNode* pTmp = pNode;
		// next
		pNode = (ShaderNode*)pNode->next;

		delete pTmp;
	}
}

void ShaderMan::privAddToFront(ShaderNodeLink *node, ShaderNodeLink *&head)
{
	assert(node != 0);
	if (head == 0)
	{
		head = node;
		node->next = 0;
		node->prev = 0;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
}
