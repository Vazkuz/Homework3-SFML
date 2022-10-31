#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Game.h"
using namespace gm;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!");
    window.setFramerateLimit(60);
    Game g;

    while (window.isOpen())
    {
        g.handleInput(window);
        g.update(window);
        g.render(window);


    }
    return 0;
}