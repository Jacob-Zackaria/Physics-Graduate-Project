#ifndef IMAGE_NAME
#define IMAGE_NAME


#include "EnumBase.h"

struct ImageName : public EnumBase
{
	ImageName(ImageName::Name n)
	{
		this->value = (unsigned int)n;
	}

	enum class Name
	{
		Root = 0x30000,

		//Background
		Background,

		// Effects
		Bang,
		Flame,
		Smoke,
		Trail,
		Projector,

		//Tower platform
		TowerPlatform,

		// external
		Space,
		Space2,
		Space3,
		Space4,

		// Gears
		Gear1,

		//Egg
		Egg,

		// Sling
		Sling,
		Sling_Stump0,
		Sling_Stump1,

		// Other
		Alien_Blue,
		Alien_Green,
		Alien_Red,
		Stitch,

		// Feather
		FeatherYellow,
		FeatherRed,
		FeatherBlack,
		FeatherBlue,
		FeatherGreen,
		FeatherWhite,

		// Red Bird
		RedBird0,
		RedBird1,
		RedBird2,
		RedBird3,
		RedBird4,

		// Yellow Bird
		YellowBird0,
		YellowBird1,
		YellowBird2,
		YellowBird3,
		YellowBird4,
		YellowBird5,

		// Green Bird
		GreenBird0,
		GreenBird1,
		GreenBird2,
		GreenBird3,
		GreenBird4,

		// Big Bird
		BigBird0,
		BigBird1,
		BigBird2,

		// White Bird
		WhiteBird0,
		WhiteBird1,
		WhiteBird2,
		WhiteBird3,
		WhiteBird4,
		WhiteBird5,

		// Bomb Bird
		BombBird0,
		BombBird1,
		BombBird2,
		BombBird3,
		BombBird4,

		// Blue Bird
		BlueBird0,
		BlueBird1,
		BlueBird2,
		BlueBird3,

		// Minion Pig
		MinionPig0,
		MinionPig1,
		MinionPig2,
		MinionPig3,
		MinionPig4,
		MinionPig5,
		MinionPig6,
		MinionPig7,
		MinionPig8,

		// Corporal Pig
		CorporalPig0,
		CorporalPig1,
		CorporalPig2,
		CorporalPig3,
		CorporalPig4,
		CorporalPig5,
		CorporalPig6,
		CorporalPig7,
		CorporalPig8,

		// Foreman Pig
		ForemanPig0,
		ForemanPig1,
		ForemanPig2,
		ForemanPig3,
		ForemanPig4,
		ForemanPig5,
		ForemanPig6,
		ForemanPig7,
		ForemanPig8,

		// King Pig
		KingPig0,
		KingPig1,
		KingPig2,
		KingPig3,
		KingPig4,
		KingPig5,
		KingPig6,
		KingPig7,
		KingPig8,

		// Wood Blocks Square
		WoodSquare0,
		WoodSquare1,
		WoodSquare2,
		WoodSquare3,

		// Wood Blocks Small Square
		WoodSmallSquare0,
		WoodSmallSquare1,
		WoodSmallSquare2,
		WoodSmallSquare3,

		// Wood Blocks Smallest Square
		WoodSmallestSquare0,
		WoodSmallestSquare1,
		WoodSmallestSquare2,
		WoodSmallestSquare3,

		// Wood Blocks Equi-Triangle
		WoodEquiTriangle0,
		WoodEquiTriangle1,
		WoodEquiTriangle2,
		WoodEquiTriangle3,

		// Wood Blocks Iso-Triangle
		WoodIsoTriangle0,
		WoodIsoTriangle1,
		WoodIsoTriangle2,
		WoodIsoTriangle3,

		// Wood Blocks Circle
		WoodCircle0,
		WoodCircle1,
		WoodCircle2,
		WoodCircle3,

		// Wood Blocks Small Circle
		WoodSmallCircle0,
		WoodSmallCircle1,
		WoodSmallCircle2,
		WoodSmallCircle3,

		// Wood Blocks Rectangle
		WoodRectangle0,
		WoodRectangle1,
		WoodRectangle2,
		WoodRectangle3,

		// Wood Blocks Small Rectangle
		WoodSmallRectangle0,
		WoodSmallRectangle1,
		WoodSmallRectangle2,
		WoodSmallRectangle3,

		// Wood Blocks Platform
		WoodPlatform0,
		WoodPlatform1,
		WoodPlatform2,
		WoodPlatform3,

		// Wood Blocks Small Platform
		WoodSmallPlatform0,
		WoodSmallPlatform1,
		WoodSmallPlatform2,
		WoodSmallPlatform3,

		// Wood Blocks Smallest Platform
		WoodSmallestPlatform0,
		WoodSmallestPlatform1,
		WoodSmallestPlatform2,
		WoodSmallestPlatform3,

		// Stone Blocks Square
		StoneSquare0,
		StoneSquare1,
		StoneSquare2,
		StoneSquare3,

		// Stone Blocks Small Square
		StoneSmallSquare0,
		StoneSmallSquare1,
		StoneSmallSquare2,
		StoneSmallSquare3,

		// Stone Blocks Smallest Square
		StoneSmallestSquare0,
		StoneSmallestSquare1,
		StoneSmallestSquare2,
		StoneSmallestSquare3,

		// Stone Blocks Equi-Triangle
		StoneEquiTriangle0,
		StoneEquiTriangle1,
		StoneEquiTriangle2,
		StoneEquiTriangle3,

		// Stone Blocks Iso-Triangle
		StoneIsoTriangle0,
		StoneIsoTriangle1,
		StoneIsoTriangle2,
		StoneIsoTriangle3,

		// Stone Blocks Circle
		StoneCircle0,
		StoneCircle1,
		StoneCircle2,
		StoneCircle3,

		// Stone Blocks Small Circle
		StoneSmallCircle0,
		StoneSmallCircle1,
		StoneSmallCircle2,
		StoneSmallCircle3,

		// Stone Blocks Rectangle
		StoneRectangle0,
		StoneRectangle1,
		StoneRectangle2,
		StoneRectangle3,

		// Stone Blocks Small Rectangle
		StoneSmallRectangle0,
		StoneSmallRectangle1,
		StoneSmallRectangle2,
		StoneSmallRectangle3,

		// Stone Blocks Platform
		StonePlatform0,
		StonePlatform1,
		StonePlatform2,
		StonePlatform3,

		// Stone Blocks Small Platform
		StoneSmallPlatform0,
		StoneSmallPlatform1,
		StoneSmallPlatform2,
		StoneSmallPlatform3,

		// Stone Blocks Smallest Platform
		StoneSmallestPlatform0,
		StoneSmallestPlatform1,
		StoneSmallestPlatform2,
		StoneSmallestPlatform3,

		// Glass Blocks Square
		GlassSquare0,
		GlassSquare1,
		GlassSquare2,
		GlassSquare3,

		// Glass Blocks Small Square
		GlassSmallSquare0,
		GlassSmallSquare1,
		GlassSmallSquare2,
		GlassSmallSquare3,

		// Glass Blocks Smallest Square
		GlassSmallestSquare0,
		GlassSmallestSquare1,
		GlassSmallestSquare2,
		GlassSmallestSquare3,

		// Glass Blocks Equi-Triangle
		GlassEquiTriangle0,
		GlassEquiTriangle1,
		GlassEquiTriangle2,
		GlassEquiTriangle3,

		// Glass Blocks Iso-Triangle
		GlassIsoTriangle0,
		GlassIsoTriangle1,
		GlassIsoTriangle2,
		GlassIsoTriangle3,

		// Glass Blocks Circle
		GlassCircle0,
		GlassCircle1,
		GlassCircle2,
		GlassCircle3,

		// Glass Blocks Small Circle
		GlassSmallCircle0,
		GlassSmallCircle1,
		GlassSmallCircle2,
		GlassSmallCircle3,

		// Glass Blocks Rectangle
		GlassRectangle0,
		GlassRectangle1,
		GlassRectangle2,
		GlassRectangle3,

		// Glass Blocks Small Rectangle
		GlassSmallRectangle0,
		GlassSmallRectangle1,
		GlassSmallRectangle2,
		GlassSmallRectangle3,

		// Glass Blocks Platform
		GlassPlatform0,
		GlassPlatform1,
		GlassPlatform2,
		GlassPlatform3,

		// Glass Blocks Small Platform
		GlassSmallPlatform0,
		GlassSmallPlatform1,
		GlassSmallPlatform2,
		GlassSmallPlatform3,

		// Glass Blocks Smallest Platform
		GlassSmallestPlatform0,
		GlassSmallestPlatform1,
		GlassSmallestPlatform2,
		GlassSmallestPlatform3,

		Not_Initialized,
	};
};

#endif