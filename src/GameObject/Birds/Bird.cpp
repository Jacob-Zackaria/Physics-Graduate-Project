#include "Bird.h"

Bird::~Bird()
{
}

Bird::Bird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Circle* graphicsObject_Circle)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Circle), bState(BirdState::NORMAL), explosionFeathers()
{
}

Bird::Bird(GameObjectName::Name name, GraphicsObject_Sprite* graphicsObject, GraphicsObject_Box* graphicsObject_Box)
	:
	GameObject2D(name, graphicsObject, graphicsObject_Box), bState(BirdState::NORMAL), explosionFeathers()
{
}

void Bird::Update(float t)
{
	// orient the bird towards its motion until impact
	if (!(this->bState == BirdState::IMPACT) && !(this->bState == BirdState::NORMAL))
	{
		float angle = atan2f(this->GetBody()->GetLinearVelocity().y, this->GetBody()->GetLinearVelocity().x);
		this->GetBody()->SetTransform(this->GetBody()->GetWorldCenter(), angle);
	}

	// **** IMPORTANT ****: Don't forget to call the base class Update!!!!!!!!
	GameObject2D::Update(t);
}
