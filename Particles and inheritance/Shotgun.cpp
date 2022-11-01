#include "Shotgun.h"

Shotgun::Shotgun(Vector2f position, int numParticles)
    : ParticleEffect(position)
{
    this->numParticles = numParticles;
    particleArray = new CircleParticle * [this->numParticles];
    CreateParticles();
}
Shotgun::~Shotgun() {

}

void Shotgun::Update() {
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

void Shotgun::CreateParticle(CircleParticle*& particle) {
    float randX = ((float(rand()) / float(RAND_MAX)) * (2 + 2)) - 2;
    float randY = ((float(rand()) / float(RAND_MAX)) * (-20 + 10)) - 10;
    //float randSize = ((float(rand()) / float(RAND_MAX)) * (9 - 1)) + 1;
    //float randLifespan = ((float(rand()) / float(RAND_MAX)) * (90 + 30)) - 30;
    particle = new CircleParticle(6, Vector2f(50, 50), 60);
    Vector2f randomVelocity = Vector2f(randX, randY);
    particle->SetPosition(position);
    particle->SetVelocity(randomVelocity);
    particle->GetShape()->setFillColor(sf::Color(123, 131, 137));
}