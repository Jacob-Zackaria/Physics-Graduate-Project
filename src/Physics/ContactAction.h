#ifndef CONTACT_ACTION_H
#define CONTACT_ACTION_H

struct b2ContactImpulse;
class b2Contact;
class Wood;
class RedBird;
class YellowBird;
class Stone;
class Glass;
class KingPig;
class MinionPig;
class Egg;
class Gear;
class SensorBox;

class ContactAction
{
public:
	static void ContactPair(RedBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(YellowBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(MinionPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(MinionPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(KingPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(KingPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Egg& bird, Gear& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(SensorBox& bird, Gear& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(SensorBox& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);


private:
	static void ShowBang(b2Contact* pContact);
};


#endif CONTACT_ACTION_H