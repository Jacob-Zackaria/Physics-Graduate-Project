// ExplosionYellowFeathers
// Andre Berthiaume, May 2017

#ifndef _ExplosionFeathers
#define _ExplosionFeathers

#include "ManagedPool.h"
#include "SceneLink.h"

class GameObject2D;

class ExplosionFeathers : public ManagedPool
{
private:
	virtual GameObject2D* CreateNew() override;

public:

	enum class FeatherType
	{
		YELLOW,
		RED,
		BLACK,
		BLUE,
		GREEN,
		WHITE
	};

	ExplosionFeathers() = default;
	virtual ~ExplosionFeathers();
	ExplosionFeathers(const ExplosionFeathers&) = delete;
	ExplosionFeathers& operator=(const ExplosionFeathers&) = delete;

	void Create(FeatherType newFeather, float pixx, float pixy);
	//void privAddToFront(SceneLink* node, SceneLink*& head);
	//void privRemove(SceneLink* pNewData, SceneLink*& pHead);

	//SceneLink* pLinks;
	FeatherType featherType = FeatherType::YELLOW;
	// Note: missing stuff to add
	// - recall live feathers and 
	// - delete may leak if feathers sill active
};


#endif _ExplosionYellowFeathers
