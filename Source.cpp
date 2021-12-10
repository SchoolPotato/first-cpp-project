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
	player.init("art/ninja.png", sf::Glsl::Vec2(viewSize.x * 0.25f, viewSize.y * 0.0f), 100);
}
void updateInput() {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				player.jump(750.0f);
			}
		}

		// Detect ESC key to close the game
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
			window.close();
		}
	}
}
void update(float dt) {
	player.update(dt);
}

int main() {
	// Initialize Game Objects
	sf::Clock clock;
	init();

	while (window.isOpen()) {
		// Handle Keyboard Events
		updateInput();
		sf::Time dt = clock.restart();
		update(dt.asSeconds());
		// Update Game Objects in the scene
		window.clear(color);
		draw();
		// Render Game Objects
		window.display();
		}
	return 0;
}