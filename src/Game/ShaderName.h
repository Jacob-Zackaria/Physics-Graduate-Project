#ifndef SHADER_NAME
#define SHADER_NAME

#include "EnumBase.h"

struct ShaderName : public EnumBase
{
	ShaderName(ShaderName::Name n)
	{
		this->value = (unsigned int)n;
	}

	enum class Name
	{
		ROOT = 0x50000,

		COLOR_LIGHT,
		TEXTURE_SIMPLE,
		TEXTURE_POINT_LIGHT,
		SPRITE,
		SPRITE_LINE,
		SPRITE_TRI,

		NOT_INITIALIZED
	};
};

#endif