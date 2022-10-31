#include "Particle.h"
#include "CircleParticle.h"

#include "ParticleEffect.h"

using namespace sf;

// Global Variables
const int ARRAY_LENGTH = 40;
CircleParticle* particleArray[ARRAY_LENGTH];



ParticleEffect::ParticleEffect(Vector2f position)
{
    this->position = position;
    CreateParticles();
}

ParticleEffect::~ParticleEffect() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        delete particleArray[i];
        particleArray[i] = nullptr;
    }
    delete *particleArray;
    *particleArray = nullptr;
}

void ParticleEffect::Update() {
    particlesAlive = 0;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
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

void ParticleEffect::Render(RenderWindow& window) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (particleArray[i]) {
            particleArray[i]->Render(window);
        }
    }
}

void ParticleEffect::CreateParticles(){
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        *(particleArray + i) = nullptr;
    }
}

//creates a new particle for every element of the particles array
void ParticleEffect::Emit() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        int randX = ((float(rand()) / float(RAND_MAX)) * (15 + 15)) - 15;
        int randY = ((float(rand()) / float(RAND_MAX)) * (15 + 15)) - 15;
        float randSize = ((float(rand()) / float(RAND_MAX)) * (12 - 1)) + 1;
        float randLifespan = ((float(rand()) / float(RAND_MAX)) * (90 + 30)) - 30;
        particleArray[i] = new CircleParticle(randSize, this->position, randLifespan);
        Vector2f randomVelocity = Vector2f(randX, randY);
        particleArray[i]->SetVelocity(randomVelocity);
    }
}