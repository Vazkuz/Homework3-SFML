#include "Smoke.h"

Smoke::Smoke(Vector2f position, int numParticles)
	: ParticleEffect(position, numParticles)
{
	CreateParticles();
}
Smoke::~Smoke() {

}

void Smoke::CreateParticle(CircleParticle*& particle) {
	int randX = ((float(rand()) / float(RAND_MAX)) * (5 + 5)) - 5;
	int randY = ((float(rand()) / float(RAND_MAX)) * (-5 + 2)) - 2;
	float randSize = ((float(rand()) / float(RAND_MAX)) * (12 - 1)) + 1;
	float randLifespan = ((float(rand()) / float(RAND_MAX)) * (90 + 30)) - 30;
	particle = new CircleParticle(randSize, Vector2f(50, 50), randLifespan);
	Vector2f randomVelocity = Vector2f(randX, randY);
	particle->SetPosition(position);
	particle->SetVelocity(randomVelocity);
}