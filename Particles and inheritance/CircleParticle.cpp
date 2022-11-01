#include "CircleParticle.h"

//CircleParticle::CircleParticle() 
//	: Particle(Vector2f(0, 0), 0)
//{
//	shape = new CircleShape();
//	this->radius = 0;
//	shape->setRadius(radius);
//	shape->setPosition(Vector2f(0,0));
//}
CircleParticle::CircleParticle(float radius, Vector2f position, float lifespan)
	: Particle(position, lifespan)
{
	shape = new CircleShape();
	this->radius = radius;
	shape->setRadius(radius);
	shape->setPosition(position);
}
CircleParticle::~CircleParticle() {
	delete shape;
	shape = nullptr;
}

float CircleParticle::GetRadius()
{
	return radius;
}

void CircleParticle::SetRadius(float radius)
{
	this->radius = radius;
}

CircleShape* CircleParticle::GetShape()
{
	return shape;
}

void CircleParticle::Update() {
	Particle::Update();
	shape->setPosition(GetPosition());
}
void CircleParticle::Render(RenderWindow& window) {
	window.draw(*shape);
}