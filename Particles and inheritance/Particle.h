#ifndef PARTICLE_H
#define PARTICLE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

class Particle
{
private:
    Vector2f position;
    Vector2f velocity;

protected:
    bool alive = false;
    float lifespan;
    float lifespanRemaining;

public:

    Particle(Vector2f position, float lifespan);
    ~Particle();
    virtual void Update();
    virtual void Render(RenderWindow& window) = 0;

    Vector2f GetPosition();
    void SetPosition(Vector2f position);

    Vector2f GetVelocity();
    void SetVelocity(Vector2f velocity);

    float GetLifespan();
    void SetLifespan(float lifespan);

    float GetLifespanRemaining();
    void SetLifespanRemaining(float lifespanRemaining);

    bool IsAlive();
    void SetAlive(bool alive);

};

#endif
