#ifndef FIREWORK_H
#define FIREWORK_H

#include "ParticleEffect.h"

class Firework : public ParticleEffect
{
public:
	Firework(Vector2f position, int numParticles);
	~Firework();

	void CreateParticle(CircleParticle* &particle);
};

#endif