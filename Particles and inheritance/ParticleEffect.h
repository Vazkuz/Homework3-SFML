#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
//#include <iostream>

using namespace sf;

class ParticleEffect
{
public:

	Vector2f position;

	int particlesAlive;

	ParticleEffect(Vector2f position);
	~ParticleEffect();

	void CreateParticles();
	//virtual void CreateParticle() = 0;
	virtual void Emit();

	void Update();
	void Render(RenderWindow& window);
};

#endif