#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "ImageMan.h"

void LoadImages()
{
	// Effects
	ImageMan::addImage(ImageName::Name::Bang, TextName::AngryBirds, Rect(674, 354, 88, 88)); // Bang
	ImageMan::addImage(ImageName::Name::Flame, TextName::Flame, Rect(0, 0, 48, 90)); // Flame
	ImageMan::addImage(ImageName::Name::Smoke, TextName::AngryBirds, Rect(167, 514, 118, 110)); // Smoke
	ImageMan::addImage(ImageName::Name::Trail, TextName::AngryBirds, Rect(0, 345, 36, 32)); // Trail
	ImageMan::addImage(ImageName::Name::Projector, TextName::AngryBirds, Rect(20, 751, 14, 14)); // Projector (glass piece)

	// Background
	ImageMan::addImage(ImageName::Name::Background, TextName::Background, Rect(0, 0, 1279, 1335)); // Background

	//Tower Platform
	ImageMan::addImage(ImageName::Name::TowerPlatform, TextName::TowerPlatform, Rect(0, 0, 155, 43)); // TowerPlatform

	//Space
	ImageMan::addImage(ImageName::Name::Space, TextName::Space, Rect(0, 0, 899, 359)); //Space
	ImageMan::addImage(ImageName::Name::Space2, TextName::Space2, Rect(0, 0, 799, 599)); //Space2
	ImageMan::addImage(ImageName::Name::Space3, TextName::Space3, Rect(0, 0, 625, 312)); //Space3
	ImageMan::addImage(ImageName::Name::Space4, TextName::Space4, Rect(0, 0, 799, 532)); //Space4

	//Gear 1
	ImageMan::addImage(ImageName::Name::Gear1, TextName::Gears, Rect(390, 3, 106, 106)); //Gear1

	// Egg
	ImageMan::addImage(ImageName::Name::Egg, TextName::AngryBirds, Rect(668, 820, 44, 57)); // Egg

	// Sling
	ImageMan::addImage(ImageName::Name::Sling, TextName::AngryBirds, Rect(839, 25, 18, 23));
	ImageMan::addImage(ImageName::Name::Sling_Stump0, TextName::AngryBirds, Rect(0, 0, 39, 200)); // Sling Stump 0
	ImageMan::addImage(ImageName::Name::Sling_Stump1, TextName::AngryBirds, Rect(831, 0, 46, 126)); // Sling Stump 1

	// Birds
	ImageMan::addImage(ImageName::Name::RedBird0, TextName::AngryBirds, Rect(902, 798, 47, 45)); // Red 0
	ImageMan::addImage(ImageName::Name::RedBird1, TextName::AngryBirds, Rect(950, 798, 47, 45)); // Red 1
	ImageMan::addImage(ImageName::Name::RedBird2, TextName::AngryBirds, Rect(956, 845, 51, 43)); // Red 2
	ImageMan::addImage(ImageName::Name::RedBird3, TextName::AngryBirds, Rect(853, 891, 48, 47)); // Red 3
	ImageMan::addImage(ImageName::Name::RedBird4, TextName::AngryBirds, Rect(903, 891, 51, 43)); // Red 4
	ImageMan::addImage(ImageName::Name::GreenBird0, TextName::AngryBirds, Rect(931, 528, 101, 74)); // Green 0
	ImageMan::addImage(ImageName::Name::YellowBird0, TextName::AngryBirds, Rect(667, 879, 60, 55)); // Yellow 0
	ImageMan::addImage(ImageName::Name::YellowBird1, TextName::AngryBirds, Rect(732, 800, 59, 55)); // Yellow 1
	ImageMan::addImage(ImageName::Name::YellowBird2, TextName::AngryBirds, Rect(587, 915, 70, 53)); // Yellow 2
	ImageMan::addImage(ImageName::Name::YellowBird3, TextName::AngryBirds, Rect(732, 744, 59, 55)); // Yellow 3
	ImageMan::addImage(ImageName::Name::YellowBird4, TextName::AngryBirds, Rect(857, 744, 75, 53)); // Yellow 4
	ImageMan::addImage(ImageName::Name::YellowBird5, TextName::AngryBirds, Rect(792, 744, 60, 54)); // Yellow 5
	ImageMan::addImage(ImageName::Name::BombBird0, TextName::AngryBirds, Rect(410, 724, 60, 81)); // Bomb 0
	ImageMan::addImage(ImageName::Name::BigBird0, TextName::AngryBirds, Rect(297, 751, 99, 96)); // Big Bird 0
	ImageMan::addImage(ImageName::Name::BigBird1, TextName::AngryBirds, Rect(634, 156, 98, 98)); // Big Bird 1
	ImageMan::addImage(ImageName::Name::BigBird2, TextName::AngryBirds, Rect(813, 258, 98, 93)); // Big Bird 2
	ImageMan::addImage(ImageName::Name::WhiteBird0, TextName::AngryBirds, Rect(409, 352, 82, 95)); // White Bird 0
	ImageMan::addImage(ImageName::Name::BlueBird0, TextName::AngryBirds, Rect(1, 379, 31, 30)); // Blue Bird 0

	// Feathers
	ImageMan::addImage(ImageName::Name::FeatherYellow, TextName::AngryBirds, Rect(29, 442, 10, 30)); // yellow feather
	ImageMan::addImage(ImageName::Name::FeatherRed, TextName::AngryBirds, Rect(0, 475, 14, 31)); // red feather
	ImageMan::addImage(ImageName::Name::FeatherBlack, TextName::AngryBirds, Rect(20, 598, 11, 26)); // black feather
	ImageMan::addImage(ImageName::Name::FeatherBlue, TextName::AngryBirds, Rect(27, 654, 10, 22)); // blue feather
	ImageMan::addImage(ImageName::Name::FeatherGreen, TextName::AngryBirds, Rect(23, 274, 9, 34)); // green feather, kinda
	ImageMan::addImage(ImageName::Name::FeatherWhite, TextName::AngryBirds, Rect(24, 627, 9, 25)); // white feather

	// Pigs
	ImageMan::addImage(ImageName::Name::MinionPig0, TextName::AngryBirds, Rect(928, 445, 80, 79)); // Minion Pig 0
	ImageMan::addImage(ImageName::Name::MinionPig1, TextName::AngryBirds, Rect(586, 528, 80, 79)); // Minion Pig 1
	ImageMan::addImage(ImageName::Name::MinionPig2, TextName::AngryBirds, Rect(586, 607, 80, 79)); // Minion Pig 2
	ImageMan::addImage(ImageName::Name::MinionPig3, TextName::AngryBirds, Rect(409, 891, 80, 75)); // Minion Pig 3
	ImageMan::addImage(ImageName::Name::MinionPig4, TextName::AngryBirds, Rect(667, 530, 81, 74)); // Minion Pig 4
	ImageMan::addImage(ImageName::Name::MinionPig5, TextName::AngryBirds, Rect(748, 530, 81, 75)); // Minion Pig 5
	ImageMan::addImage(ImageName::Name::MinionPig6, TextName::AngryBirds, Rect(587, 688, 80, 74)); // Minion Pig 6
	ImageMan::addImage(ImageName::Name::MinionPig7, TextName::AngryBirds, Rect(587, 763, 81, 75)); // Minion Pig 7
	ImageMan::addImage(ImageName::Name::MinionPig8, TextName::AngryBirds, Rect(586, 840, 81, 74)); // Minion Pig 8
	ImageMan::addImage(ImageName::Name::CorporalPig0, TextName::AngryBirds, Rect(493, 445, 94, 85)); // Corporal Pig 0
	ImageMan::addImage(ImageName::Name::KingPig0, TextName::AngryBirds, Rect(41, 0, 126, 154)); // King Pig 0
	ImageMan::addImage(ImageName::Name::KingPig1, TextName::AngryBirds, Rect(40, 466, 127, 153)); // King Pig 1
	ImageMan::addImage(ImageName::Name::KingPig2, TextName::AngryBirds, Rect(168, 1, 127, 153)); // King Pig 2
	ImageMan::addImage(ImageName::Name::KingPig3, TextName::AngryBirds, Rect(40, 156, 128, 154)); // King Pig 3
	ImageMan::addImage(ImageName::Name::KingPig4, TextName::AngryBirds, Rect(295, 1, 129, 153)); // King Pig 4
	ImageMan::addImage(ImageName::Name::KingPig5, TextName::AngryBirds, Rect(40, 311, 127, 153)); // King Pig 5
	ImageMan::addImage(ImageName::Name::KingPig6, TextName::AngryBirds, Rect(424, 1, 127, 153)); // King Pig 6
	ImageMan::addImage(ImageName::Name::KingPig7, TextName::AngryBirds, Rect(40, 620, 128, 155)); // King Pig 7
	ImageMan::addImage(ImageName::Name::KingPig8, TextName::AngryBirds, Rect(40, 776, 127, 154)); // King Pig 8

	// Glass
	ImageMan::addImage(ImageName::Name::GlassEquiTriangle0, TextName::Glass, Rect(84, 85, 84, 83)); // Glass Equi Triangle 0
	ImageMan::addImage(ImageName::Name::GlassPlatform0, TextName::Glass, Rect(288, 214, 205, 22)); // Glass Platform 0
	ImageMan::addImage(ImageName::Name::GlassPlatform1, TextName::Glass, Rect(288, 192, 205, 22)); // Glass Platform 1
	ImageMan::addImage(ImageName::Name::GlassPlatform2, TextName::Glass, Rect(288, 236, 205, 22)); // Glass Platform 2
	ImageMan::addImage(ImageName::Name::GlassPlatform3, TextName::Glass, Rect(288, 170, 205, 22)); // Glass Platform 3
	ImageMan::addImage(ImageName::Name::GlassCircle0, TextName::Glass, Rect(169, 235, 73, 74)); // Glass Circle 0

	// Wood
	ImageMan::addImage(ImageName::Name::WoodPlatform0, TextName::Wood, Rect(287, 168, 206, 22)); // Wood Platform 0
	ImageMan::addImage(ImageName::Name::WoodPlatform1, TextName::Wood, Rect(287, 190, 206, 22)); // Wood Platform 1
	ImageMan::addImage(ImageName::Name::WoodPlatform2, TextName::Wood, Rect(287, 212, 206, 22)); // Wood Platform 2
	ImageMan::addImage(ImageName::Name::WoodPlatform3, TextName::Wood, Rect(287, 234, 206, 22)); // Wood Platform 3
	ImageMan::addImage(ImageName::Name::WoodEquiTriangle0, TextName::Wood, Rect(85, 1, 83, 83)); // Wood Equi Triangle 0
	ImageMan::addImage(ImageName::Name::WoodIsoTriangle0, TextName::Wood, Rect(168, 1, 81, 81)); // Wood Iso Triangle 0
	ImageMan::addImage(ImageName::Name::WoodSquare0, TextName::Wood, Rect(0, 0, 84, 84)); // Wood Square 0

	// Stone
	ImageMan::addImage(ImageName::Name::StonePlatform0, TextName::Stone, Rect(247, 168, 205, 22)); // Stone Platform 0
	ImageMan::addImage(ImageName::Name::StonePlatform1, TextName::Stone, Rect(247, 190, 205, 22)); // Stone Platform 1
	ImageMan::addImage(ImageName::Name::StonePlatform2, TextName::Stone, Rect(247, 212, 205, 22)); // Stone Platform 2
	ImageMan::addImage(ImageName::Name::StonePlatform3, TextName::Stone, Rect(247, 234, 205, 22)); // Stone Platform 3
	ImageMan::addImage(ImageName::Name::StoneCircle0, TextName::Stone, Rect(169, 82, 76, 75)); // Stone Circle 0
	ImageMan::addImage(ImageName::Name::StoneSmallSquare0, TextName::Stone, Rect(1, 337, 42, 42)); // Stone Small Square 0
}

#endif