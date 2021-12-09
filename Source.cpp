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
sf::RenderWindow window(vm, "WindowName", sf::Style::Default);

int main() {

	std::cout << "Hello!" << std::endl;

	return 0;
}