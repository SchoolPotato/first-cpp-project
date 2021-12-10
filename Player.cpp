#include "Player.h"
#include <iostream>
#include <conio.h>

Player::Player() {

}

void Player::init(std::string textureName, sf::Glsl::Vec2 position, float mass) {
	m_position = position;
	m_mass = mass;
	m_grounded = true;

	jumpCount = 0;

	// Load a texture
	m_texture.loadFromFile(textureName.c_str());

	// Create Sprite and Attach a Texture
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);

}

void Player::update(float dt) {
	m_force -= m_mass * m_gravity * dt;
	m_position.y -= m_force * dt;
	m_position.y -= m_velocity * dt;
	m_sprite.setPosition(m_position);

	if (m_velocity > 0) {
		m_velocity--;
	}

	if (m_position.y >= 180 * 0.75f) {
		m_position.y = 180 * 0.75f;
		m_force = 0;
		m_grounded = true;
		jumpCount = 0;
	}
}

void Player::jump(float velocity) {
	if (jumpCount < 2) {
		if (jumpCount == 1) {
			m_force = 0;
		}
		jumpCount++;

		m_velocity = velocity;
		m_grounded = false;
	}
}

sf::Sprite Player::getSprite() {
	return m_sprite;
}