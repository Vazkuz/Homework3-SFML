#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "ParticleEffect.h"

class Shotgun : public ParticleEffect
{
public:
	Shotgun(Vector2f position, int numParticles);
	~Shotgun();

	void Update();

	void CreateParticle(CircleParticle*& particle);
};

#endif
