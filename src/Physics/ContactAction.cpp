#include "ContactAction.h"
#include "Box2D.h"
#include "Wood.h"
#include "Stone.h"
#include "Glass.h"
#include "Game.h"
#include "Egg.h"
#include "SensorBox.h"
#include "MinionPig.h"
#include "KingPig.h"
#include "YellowBird.h"
#include "RedBird.h"
#include "PixelToMeter.h"
#include "EffectFactory.h"
#include "GameObjectMan.h"
#include "BangEvent.h"
#include "TimerMan.h"
#include "AudioManager.h"
#include "ExplosionFeathers.h"
#include "SceneManager.h"

void ContactAction::ContactPair(RedBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
	
}

void ContactAction::ContactPair(RedBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(RedBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(RedBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(RedBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
			if (bird.punchMode && (vel.LengthSquared() > 30.0f))
			{
				pContact->SetEnabled(false);
				block.ReduceHealth(10000);

				// Slow the bird down by some factor
				//bird.GetBody()->ApplyLinearImpulse(.5f * bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
			}
			else
			{
				block.ReduceHealth(pImpulse->normalImpulses[i]);
				bird.ReduceHealth(pImpulse->normalImpulses[i]);
			}
			
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		b2Vec2 pos = bird.GetBody()->GetPosition();
		bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		b2Vec2 pos = bird.GetBody()->GetPosition();
		bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 8.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		b2Vec2 pos = bird.GetBody()->GetPosition();
		bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(YellowBird& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 3.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		b2Vec2 pos = bird.GetBody()->GetPosition();
		bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);

		AudioManager::Play(Audio::Name::PIG_SING_7);
	}
}

void ContactAction::ContactPair(YellowBird& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		b2Vec2 pos = bird.GetBody()->GetPosition();
		bird.explosionFeathers.Create(ExplosionFeathers::FeatherType::YELLOW, MeterToPixel(pos.x), MeterToPixel(pos.y));

		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 12.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 10.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(MinionPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, Wood& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 15.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, Stone& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, Glass& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 20.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, MinionPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(KingPig& bird, KingPig& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse->normalImpulses[0] > 5.0f)
	{
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

			// Record Damage
			block.ReduceHealth(pImpulse->normalImpulses[i]);

			bird.ReduceHealth(pImpulse->normalImpulses[i]);
		}
	}

	if (pImpulse->normalImpulses[0] > 40.0f)
	{
		ShowBang(pContact);
	}
}

void ContactAction::ContactPair(Egg& bird, Gear&, b2Contact*, const b2ContactImpulse*)
{
	bird.NextLevel();
}

void ContactAction::ContactPair(SensorBox& , Gear& block, b2Contact*, const b2ContactImpulse* )
{
	SceneManager::DeleteSceneObject(SceneManager::GetCurrentScene(), (GameObject2D*)&block);
}

void ContactAction::ContactPair(SensorBox& , Glass& block, b2Contact* , const b2ContactImpulse* )
{
	SceneManager::DeleteSceneObject(SceneManager::GetCurrentScene(), (GameObject2D*)&block);
}

void ContactAction::ShowBang(b2Contact* pContact)
{
	//normal manifold contains all info...
	int numPoints = pContact->GetManifold()->pointCount;

	//...world manifold is helpful for getting locations
	b2WorldManifold worldManifold;
	pContact->GetWorldManifold(&worldManifold);

	//DebugMsg::out("Drawing %i Bangs\n", numPoints);

	//draw collision points
	for (int i = 0; i < numPoints; i++)
	{
		Rect rect = Rect(MeterToPixel(worldManifold.points[i].x), MeterToPixel(worldManifold.points[i].y), 15.0f, 15.0f);

		BangEvent* newEvent = new BangEvent(EffectFactory::CreateEffect(GameObjectName::Name::Bang, rect));
		TimerMan::AddEvent(0.1f, newEvent);
	}
}