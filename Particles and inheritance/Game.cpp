#include "Game.h"
#include "Particle.h"
#include "Firework.h"
#include "Shotgun.h"

using namespace std;
using namespace gm;
using namespace sf;

ParticleEffect* pEffect = nullptr;

enum effectType{
	T_Firework,
	T_Smoke
};

effectType effect = effectType::T_Firework;

Game::Game() {

}

Game::~Game() {

}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		if (Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			effect = effectType::T_Firework;
		}
		if (Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			effect = effectType::T_Smoke;
		}

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			if (pEffect != nullptr) {
				delete pEffect;
				pEffect = nullptr;
			}
			if (effect == effectType::T_Firework) {
				pEffect = new Firework(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y), 100);
			}
			if (effect == effectType::T_Smoke) {
				pEffect = new Shotgun(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y), 40);
			}
		}
	}
}

void Game::update(sf::RenderWindow& window) {
	if (pEffect) {
		pEffect->Update();
		if (pEffect->GetParticlesAlive() <= 0) {
			delete pEffect;
			pEffect = nullptr;
		}
	}
}

void Game::render(sf::RenderWindow& window) {
	window.clear();
	if (pEffect) {
		pEffect->Render(window);
	}
	window.display();
}
