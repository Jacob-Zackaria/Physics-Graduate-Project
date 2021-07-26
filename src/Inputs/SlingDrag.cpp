#include "SlingDrag.h"
#include "SlingQueue.h"
#include "Game.h"
#include "PixelToMeter.h"
#include "BirdFactory.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "TimerMan.h"
#include "TrailCreation.h"
SlingDrag::SlingDrag(b2Vec2 newSlingPos, float newLimit)
	:
	slingPos(newSlingPos),
	limit(newLimit),
	pData{},
	pTraj()
{
}

SlingDrag::~SlingDrag()
{
}

void SlingDrag::Update()
{
	// check if sling queue has bird and is not loaded
	if ((SlingQueue::GetCurrentCount() > 0) && (SlingQueue::GetSlingState() != SlingQueue::SlingState::LOADED))
	{
		// if not, load next bird
		SlingQueue::LoadNext();
	}

	// check if sling is loaded
	if (SlingQueue::GetSlingState() == SlingQueue::SlingState::LOADED)
	{
		// get loaded bird.
		Bird* loadedObj = (Bird*)SlingQueue::GetLoadedObject();

		// check mouse state
		InputManager::MouseState mState = InputManager::GetMouseState();
		if (mState == InputManager::MouseState::LEFT)
		{
			
			// get mouse position
			float xPos;
			float yPos;
			Mouse::GetCursor(xPos, yPos);

			//// Important: inverts the y values to get 0,0 at bottom left.
			yPos = Game::GetWindowHeight() - yPos;

			// get world mouse pos
			b2Vec2 WorldMousePos = b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));

			// inside bird?
			b2Body* pBody = loadedObj->GetBody();
			// check fixture
			if (pBody->GetFixtureList()->TestPoint(WorldMousePos))
			{
				// if inside set state to dragged.
				loadedObj->bState = Bird::BirdState::DRAGGED;
			}
			else
			{
				// remove trajectory
				this->pTraj.DeleteTrace();
			}

			// if bird is dragged.
			if (loadedObj->bState == Bird::BirdState::DRAGGED)
			{
				// vector for current mouse position
				b2Vec2 DrawPoint(xPos, yPos);

				{
					// direction vector from current sling position to mouse vector 
					b2Vec2 drawVector = (slingPos - DrawPoint);

					// find length of the direction vector
					float len = drawVector.Normalize();

					// check if length is greater than limit.
					if (len > limit)
					{
						// if yes, set length to limit.
						len = limit;
					}

					// get angle from direction vector.
					float cAngle = atan2f(drawVector.y, drawVector.x);

					// check if angle is inbetween the given angles. { wrong method, need to fix }
					if ((cAngle > -MATH_PI && cAngle < -MATH_PI2) || (cAngle > MATH_PI2 && cAngle < MATH_PI))
					{
						cAngle += MATH_PI; // wrong, need to fix.
					}

					// find new position for the loaded object from the direction vector and length.
					b2Vec2 newPos = (slingPos - (0.5f * len * drawVector));
					loadedObj->SetPos(newPos.x, newPos.y);

					// set angle for loaded object.
					loadedObj->SetCurrentAngle(cAngle);

					// draw projected path.
					this->pTraj.Trace(loadedObj->GetBody()->GetPosition(), (0.0137f * loadedObj->GetBody()->GetMass() * len * drawVector), 30);
				}

				// assign slings, same as that of the loaded object
				uint8_t i = 0;
				while(i < 2)
				{
					b2Vec2 DrawVector = (this->pData[i].anchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
					float len = DrawVector.Normalize();

					// Cap the sling's extension
					if (len > this->pData[i].drawLimit)
					{
						len = this->pData[i].drawLimit;
					}

					// Get the sprite angle through Atan2 (you remember? http://facweb.cs.depaul.edu/andre/GAM325/week4.htm )
					// also: http://en.cppreference.com/w/c/numeric/math/atan2
					float cAngle = atan2f(DrawVector.y, DrawVector.x);

					this->pData[i].pObj->SetCurrentAngle(cAngle);

					// rescaling the sprite based on the sling's extension
					this->pData[i].pObj->SetScaleX((len / this->pData[i].pObj->GetOriginalWidth()));

					// Adjust sprite position
					//*
					b2Vec2 newCenterPos = (this->pData[i].anchor - (0.5f * len * DrawVector));
					this->pData[i].pObj->SetPos(newCenterPos.x, newCenterPos.y);

					i++;
				}
			}
		}
		else if(loadedObj->bState == Bird::BirdState::DRAGGED)
		{
			// change bird state
			loadedObj->bState = Bird::BirdState::FLYING;
			loadedObj->GetBody()->SetActive(true);

			// find direction vector of loaded bird from sling
			b2Vec2 dir = slingPos - b2Vec2(loadedObj->GetPosX(), loadedObj->GetPosY());

			// find length of the direction vector.
			float mag = dir.Normalize();

			// apply an impulse to the direction vector.
			b2Vec2 imp = (mag * 1.7f) * dir;
			loadedObj->GetBody()->ApplyLinearImpulse(imp, loadedObj->GetBody()->GetWorldCenter(), true);

			// set sling as empty.
			SlingQueue::SetState(SlingQueue::SlingState::EMPTY);

			// reset slings to original state
			uint8_t i = 0;
			while (i < 2)
			{
				this->pData[i].pObj->SetPos(this->pData[i].origState.x, this->pData[i].origState.y);
				this->pData[i].pObj->SetCurrentAngle(this->pData[i].origAngle);
				this->pData[i].pObj->SetScale(1.0f, 1.0f);

				i++;
			}

			// clear existing trail, if exists
			SlingQueue::GetTrailCollection()->DeleteTrail();

			// create trail
			TimerMan::AddEvent(0.03f, new TrailCreation(loadedObj, SlingQueue::GetTrailCollection()));

			// play audio
			AudioManager::Play(Audio::Name::RED_BIRD_YELL);
		}
	}
}

void SlingDrag::AddSling1(GameObject2D* newObj, b2Vec2 newAnchor, const float newDrawLimit)
{
	this->pData[0].pObj = newObj;
	this->pData[0].anchor = newAnchor;
	this->pData[0].drawLimit = newDrawLimit;
	this->pData[0].origState = Rect(newObj->GetPosX(), newObj->GetPosY(), newObj->GetOriginalWidth(), newObj->GetOriginalHeight());
	this->pData[0].origAngle = newObj->GetCurrentAngle();
}

void SlingDrag::AddSling2(GameObject2D* newObj, b2Vec2 newAnchor, const float newDrawLimit)
{
	this->pData[1].pObj = newObj;
	this->pData[1].anchor = newAnchor;
	this->pData[1].drawLimit = newDrawLimit;
	this->pData[1].origState = Rect(newObj->GetPosX(), newObj->GetPosY(), newObj->GetOriginalWidth(), newObj->GetOriginalHeight());
	this->pData[1].origAngle = newObj->GetCurrentAngle();
}
