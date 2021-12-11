#include <iostream>
#include <conio.h>

#include <glad/glad.h>
#include <glad.c>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"

sf::Glsl::Vec2 viewSize(640/2, 360/2);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ninja Game", sf::Style::Default);
sf::Color color(25, 05, 15);

sf::Texture skyTexture;
sf::Sprite skySprite;
Player player;


void draw() {
	window.draw(skySprite);
	window.draw(player.getSprite());
	// window.draw(playerSprite);
}
void init() {
	// Load sky texture
	skyTexture.loadFromFile("art/skyTexture.png");
	skySprite.setTexture(skyTexture);

	// Load Ninja
	player.init("art/ninjaSheet.png", sf::Glsl::Vec2(viewSize.x * 0.25f, viewSize.y * 0.0f), 50);
}
void updateInput(float dt) {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Z) {
				player.jump(325.0f);
			}
			if (event.key.code == sf::Keyboard::Right) {
				player.movement(true, true);
			}
			if (event.key.code == sf::Keyboard::Left) {
				player.movement(true, false);
			}
			if (event.key.code == sf::Keyboard::X) {
				player.sprinting(true);
			}
		}

		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Right) {
				player.movement(false, true);
			}
			if (event.key.code == sf::Keyboard::Left) {
				player.movement(false, false);
			}
			if (event.key.code == sf::Keyboard::X) {
				player.sprinting(false);
			}
		}

		// Detect ESC key to close the game
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
			window.close();
		}
	}
}
void update(sf::Time dt) {
	player.update(dt, 27u);
}

int main() {
	// Initialize Game Objects
	sf::Clock clock;
	init();

	while (window.isOpen()) {
		// Handle Keyboard Events
		sf::Time dt = clock.restart();
		updateInput(dt.asSeconds());
		update(dt);
		// Update Game Objects in the scene
		window.clear(color);
		draw();
		// Render Game Objects
		window.display();
		}
	return 0;
}