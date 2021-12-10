#include "Player.h"
#include <iostream>
#include <conio.h>

Player::Player() {

}

void Player::init(std::string textureName, sf::Glsl::Vec2 position, float mass) {
	m_position = position;
	m_mass = mass;
	m_grounded = true;
	m_moveRight = false;
	m_moveLeft = false;

	jumpCount = 0;

	// Load a texture

	m_textureRect = sf::IntRect(0, 0, 16, 23);

	m_texture.loadFromFile(textureName.c_str());

	// Create Sprite and Attach a Texture
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(16 / 2, 23 / 2);

}

void Player::animation(sf::Time dtFrame, unsigned int frameCount) {
	const sf::Time timeChunk{ sf::seconds(0.0417f) };
	const unsigned int numberOfAnimationFrames{ frameCount };

	sf::Time accumulatedTime;

	unsigned int currentAnimationFrame = 0u;

	accumulatedTime = accumulatedTime + dtFrame;
	while (accumulatedTime >= timeChunk) {
		accumulatedTime -= timeChunk;
		++currentAnimationFrame;
		// https://en.sfml-dev.org/forums/index.php?topic=27324.0 Use This As Reference
	}
	unsigned int frame{ currentAnimationFrame };
	m_textureRect.left = m_textureRect.left + (currentAnimationFrame * 16u);
}

void Player::update(float dt, unsigned int frameCount) {
	m_force -= m_mass * m_gravity * dt;
	m_position.y -= m_force * dt;
	m_position.y -= m_velocity * dt;
	m_sprite.setPosition(m_position);

	animation(sf::Time(), frameCount);

	m_sprite.setTextureRect(m_textureRect);

	if (m_velocity > 0) {
		m_velocity--;
	}

	if (m_moveRight == true) {
		walk(75.0f, dt);
	}

	if (m_moveLeft == true) {
		walk(-75.0f, dt);
	}

	if (m_position.y >= 180 * 0.75f) {
		m_position.y = 180 * 0.75f;
		m_force = 0;
		m_grounded = true;
		jumpCount = 0;
	}
}

void Player::jump(float velocity) {
	if (jumpCount < 1) {
		//if (jumpCount == 1) {
		//	m_force = 0;
		//}
		jumpCount++;

		m_velocity = velocity;
		m_grounded = false;
	}
}

void Player::movement(bool walking, bool right) {
	if (walking) {
		if (right) {
			m_moveRight = true;
		}
		if (!right) {
			m_moveLeft = true;
		}
	}

	if (!walking) {
		if (right) {
			m_moveRight = false;
		}
		if (!right) {
			m_moveLeft = false;
		}
	}
}

void Player::walk(float velocity, float dt) {
	m_position.x = m_position.x + velocity * dt;
}

sf::Sprite Player::getSprite() {
	return m_sprite;
}