#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	Player();
	// ~Player();

	void init(std::string textureName, sf::Glsl::Vec2, float mass);
	void update(sf::Time dt, unsigned int frameCount);
	void jump(float velocity);
	void animation(sf::Time dtFrame, unsigned int frameCount);
	void walk(float velocity, float dt);
	void movement(bool walking, bool right);
	void sprinting(bool sprinting);
	sf::Sprite getSprite();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Glsl::Vec2 m_position;

	sf::IntRect m_textureRect;

	int jumpCount = 0;
	float m_force = 0;
	float m_mass = 0;
		float m_velocity = 0;
		const float m_gravity = 4.90f;
			bool m_grounded = true;
			bool m_moveRight = false;
			bool m_moveLeft = false;
			bool m_sprinting = false;
};

