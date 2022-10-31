#include "Game.h"
#include "Particle.h"
#include "ParticleEffect.h"

using namespace std;
using namespace gm;
using namespace sf;

ParticleEffect* pEffect = nullptr;

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

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			if (pEffect != nullptr) {
				delete pEffect;
				pEffect = nullptr;
			}
			pEffect = new ParticleEffect(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
			pEffect->Emit();
		}
	}
}

void Game::update(sf::RenderWindow& window) {
	if (pEffect) {
		pEffect->Update();
		if (pEffect->particlesAlive <= 0) {
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
