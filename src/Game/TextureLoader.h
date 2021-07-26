#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "TextureMan.h"

void LoadTextures()
{
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/AngryBirdBackground.tga", TextName::Background);
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/unsorted.tga", TextName::AngryBirds);
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/stoneBlocks.tga", TextName::Stone);
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/glassBlocks.tga", TextName::Glass);
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/woodBlocks.tga", TextName::Wood);
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/slingV2.tga", TextName::Sling);
	TextureMan::addTexture("../../../../../reference/reference/Asset/Flame.tga", TextName::Flame);
	TextureMan::addTexture("MyAssets/Levels.tga", TextName::Space);
	TextureMan::addTexture("MyAssets/Space.tga", TextName::Space2);
	TextureMan::addTexture("MyAssets/SpaceLevel.tga", TextName::Space3);
	TextureMan::addTexture("MyAssets/Retro.tga", TextName::Space4);
	TextureMan::addTexture("../../../../../reference/reference/Asset/Gears/Gears.tga", TextName::Gears);
	TextureMan::addTexture("../../../../../reference/reference/Asset/AngryBirds/woodPlatform.tga", TextName::TowerPlatform);
}

#endif