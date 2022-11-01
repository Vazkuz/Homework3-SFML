#include "ParticleEffect.h"

using namespace sf;

// Global Variables
//const int ARRAY_LENGTH = 40;
//CircleParticle* particleArray[ARRAY_LENGTH];



ParticleEffect::ParticleEffect(Vector2f position)
{
    this->position = position;
    //this->numParticles = numParticles;
    //particleArray = new CircleParticle* [this->numParticles];
    //CreateParticles();
}

ParticleEffect::~ParticleEffect() {
    for (int i = 0; i < numParticles; i++) {
        delete particleArray[i];
        particleArray[i] = nullptr;
    }
    delete *particleArray;
    *particleArray = nullptr;
}

void ParticleEffect::Render(RenderWindow& window) {
    for (int i = 0; i < numParticles; i++) {
        if (particleArray[i]) {
            particleArray[i]->Render(window);
        }
    }
}

void ParticleEffect::CreateParticles(){
    for (int i = 0; i < numParticles; i++) {
        CreateParticle(particleArray[i]);
    }
}

int ParticleEffect::GetParticlesAlive() {
    return particlesAlive;
}

void ParticleEffect::SetParticlesAlive(int particlesAlive) {
    this->particlesAlive = particlesAlive;
}