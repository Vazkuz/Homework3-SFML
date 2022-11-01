#ifndef SMOKE_H
#define SMOKE_H

#include "ParticleEffect.h"

class Smoke : public ParticleEffect
{
public:
	Smoke(Vector2f position, int numParticles);
	~Smoke();

	void CreateParticle(CircleParticle*& particle);
};

#endif

