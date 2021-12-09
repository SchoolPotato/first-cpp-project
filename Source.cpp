#include <iostream>
#include <conio.h>

#include <glad/glad.h>
#include <glad.c>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

sf::Glsl::Vec2 viewSize(640/2, 360/2);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ninja Game", sf::Style::Default);
sf::Color color(25, 05, 15);

sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Texture playerTexture;
sf::Sprite playerSprite;
bool playerMoving = false;

void draw() {
	window.draw(skySprite);
	window.draw(playerSprite);
}
void init() {
	// Load sky texture
	skyTexture.loadFromFile("art/skyTexture.png");
	skySprite.setTexture(skyTexture);

	// Load Ninja
	playerTexture.loadFromFile("art/ninja.png");
	playerSprite.setTexture(playerTexture);
	sf::Glsl::Vec2 playerPosition;
	playerSprite.setPosition(sf::Glsl::Vec2(viewSize.x / 2, viewSize.y / 2));
	playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
}
void updateInput() {
	sf::Event event;

	while (window.pollEvent(event)) {
		// Player movement
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Right) {
				playerMoving = true;
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Right) {
				playerMoving = false;
			}
		}

		// Detect ESC key to close the game
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
			window.close();
		}
	}
}
void update(float dt) {
	if (playerMoving) {
		playerSprite.move(25 * dt, 0);
	}
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