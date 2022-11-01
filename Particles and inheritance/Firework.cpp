#include "Firework.h"

Firework::Firework(Vector2f position, int numParticles)
	: ParticleEffect(position)
{
    this->numParticles = numParticles;
    particleArray = new CircleParticle * [this->numParticles];
    CreateParticles();
}
Firework::~Firework() {

}

void Firework::Update() {
    particlesAlive = 0;
    for (int i = 0; i < numParticles; i++) {
        if (particleArray[i]) {
            particleArray[i]->Update();
            particlesAlive++;
            if (particleArray[i]->GetLifespanRemaining() <= 0) {
                delete particleArray[i];
                particleArray[i] = nullptr;
                particlesAlive--;
            }
        }
    }
}

void Firework::CreateParticle(CircleParticle* &particle) {
    float randX = ((float(rand()) / float(RAND_MAX)) * (15 + 15)) - 15;
	float randY = ((float(rand()) / float(RAND_MAX)) * (15 + 15)) - 15;
	float randSize = ((float(rand()) / float(RAND_MAX)) * (9 - 1)) + 1;
	float randLifespan = ((float(rand()) / float(RAND_MAX)) * (90 + 30)) - 30;
	particle = new CircleParticle(randSize, Vector2f(50,50), randLifespan);
	Vector2f randomVelocity = Vector2f(randX, randY);
	particle->SetPosition(position);
	particle->SetVelocity(randomVelocity);
    particle->GetShape()->setFillColor(sf::Color(222, 138, 31));
}