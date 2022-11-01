#include "Firework.h"

Firework::Firework(Vector2f position, int numParticles)
	: ParticleEffect(position, numParticles)
{
	CreateParticles();
}
Firework::~Firework() {

}

void Firework::CreateParticle(CircleParticle* &particle) {
    int randX = ((float(rand()) / float(RAND_MAX)) * (15 + 15)) - 15;
	int randY = ((float(rand()) / float(RAND_MAX)) * (15 + 15)) - 15;
	float randSize = ((float(rand()) / float(RAND_MAX)) * (12 - 1)) + 1;
	float randLifespan = ((float(rand()) / float(RAND_MAX)) * (90 + 30)) - 30;
	particle = new CircleParticle(randSize, Vector2f(50,50), randLifespan);
	Vector2f randomVelocity = Vector2f(randX, randY);
	particle->SetPosition(position);
	particle->SetVelocity(randomVelocity);
}