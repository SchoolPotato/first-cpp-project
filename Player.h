#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	Player();
	// ~Player();

	void init(std::string textureName, sf::Glsl::Vec2, float mass);
	void update(float dt);
	void jump(float velocity);
	sf::Sprite getSprite();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Glsl::Vec2 m_position;

	int jumpCount = 0;
	float m_force = 0;
	float m_mass = 0;
		float m_velocity = 0;
		const float m_gravity = 9.80f;
			bool m_grounded = true;
};

