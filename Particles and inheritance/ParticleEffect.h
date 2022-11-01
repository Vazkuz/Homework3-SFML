#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "CircleParticle.h"
#include <iostream>

using namespace sf;

class ParticleEffect
{
protected:
	Vector2f position;
	CircleParticle** particleArray;
	int particlesAlive;
	int numParticles;

public:

	ParticleEffect(Vector2f position, int numParticles);
	~ParticleEffect();

	void CreateParticles();
	virtual void CreateParticle(CircleParticle* &particle) = 0;
	int GetParticlesAlive();
	void SetParticlesAlive(int particlesAlive);

	void Update();
	void Render(RenderWindow& window);
};

#endif