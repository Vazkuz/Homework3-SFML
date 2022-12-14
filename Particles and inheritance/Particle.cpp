#include "Particle.h"
#include <iostream>



Particle::Particle(Vector2f position, float lifespan)
{
    this->position = position;
    this->lifespan = lifespan;
    lifespanRemaining = lifespan;
}

Particle::~Particle()
{
}

void Particle::Update()
{
    lifespanRemaining--;
    position += velocity;

}

Vector2f Particle::GetPosition() {
    return position;
}

void Particle::SetPosition(Vector2f position) {
    this->position = position;
}

Vector2f Particle::GetVelocity() {
    return velocity;
}
void Particle::SetVelocity(Vector2f velocity) {
    this->velocity = velocity;
}

float Particle::GetLifespan() {
    return lifespan;
}

void Particle::SetLifespan(float lifespan) {
    this->lifespan = lifespan;
}

float Particle::GetLifespanRemaining() {
    return lifespanRemaining;
}

void Particle::SetLifespanRemaining(float lifespanRemaining) {
    this->lifespanRemaining = lifespanRemaining;
}

bool Particle::IsAlive() {
    return alive;
}
void Particle::SetAlive(bool alive) {
    this->alive = alive;
}