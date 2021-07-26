#ifndef TEXTURE_NAME
#define TEXTURE_NAME

#include "EnumBase.h"

struct TextName : public EnumBase
{
	TextName(TextName::Name n)
	{
		this->value = (unsigned int)n;
	}

	enum Name
	{
		Root = 0x40000,

		Invaders,
		Stitch,
		AngryBirds,
		Wood,
		Glass,
		Stone,
		Space,
		Space2,
		Space3,
		Space4,
		Gears,
		Background,
		TowerPlatform,
		Sling,
		Flame,

		Not_initialized
	};
};
#endif
