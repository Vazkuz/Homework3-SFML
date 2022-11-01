#ifndef CIRCLE_PARTICLE_H
#define CIRCLE_PARTICLE_H

#include "Particle.h"

class CircleParticle :
    public Particle
{
private:
	CircleShape* shape;
	float radius;

public:
	//CircleParticle();
	CircleParticle(float radius, Vector2f position, float lifespan);
	~CircleParticle();

	float GetRadius();
	void SetRadius(float radius);

	void Update() override;
	void Render(RenderWindow& window) override;
};

#endif // !SHAPE_PARTICLE_H