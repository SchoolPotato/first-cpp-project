#include <iostream>
#include <conio.h>

#include <glad/glad.h>
#include <glad.c>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

sf::Glsl::Vec2 viewSize(640, 360);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Ninja Game", sf::Style::Default);
sf::Color color(25, 05, 15);

sf::Texture skyTexture;
sf::Sprite skySprite;
sf::Texture playerTexture;
sf::Sprite playerSprite;

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
}

int main() {
	// Initialize Game Objects
	init();

	while (window.isOpen()) {
		// Handle Keyboard Events
		// Update Game Objects in the scene
		window.clear(color);
		draw();
		// Render Game Objects
		window.display();
		}
	return 0;
}