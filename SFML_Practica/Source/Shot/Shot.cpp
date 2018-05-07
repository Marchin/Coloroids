#include "Shot\Shot.h"

namespace shot {
	Shot::Shot() {
		if (!m_texture.loadFromFile("Resources\\Shot.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(Width() / 2, Height() / 2);
		m_sprite.setColor(color::Transparent(sf::Color::Blue));
		m_speed = 1.f;
		m_direction = sf::Vector2f(0.f, 0.f);
		m_beingFired = false;
	}

	float Shot::Width() const{
		return m_sprite.getLocalBounds().width;
	}

	float Shot::Height() const{
		return m_sprite.getLocalBounds().width;
	}

	void Shot::UpdateMovement(const std::vector<sf::Sprite>& obstacles,
							const float deltaTime) {
		if (m_beingFired) {
			m_sprite.move(m_direction * m_speed * deltaTime);
			CheckCollision(obstacles);
		}
	}

	void Shot::SetDirection(sf::Vector2f direction) {
		m_direction = direction;
	}

	void Shot::CheckCollision(const std::vector<sf::Sprite>& obstacles) {
		for (int i = 0; obstacles.size(); i++) {
			if (Collision::CircleTest(m_sprite, obstacles[i])) {
				if (m_sprite.getColor() == obstacles[i].getColor()) {
					//destroy asteroid
				}
				Disable();
			}
		}
	}


	void Shot::Disable() {
		m_sprite.setColor(color::Transparent(m_sprite.getColor()));
		m_beingFired = false;
	}

	void Shot::Enable() {
		m_beingFired = true;
	}

	void Shot::SetPosition(sf::Vector2f position) {
		m_sprite.setPosition(position);
	}

	sf::Vector2f Shot::GetPosition() const {
		return m_sprite.getPosition();
	}

	sf::Color Shot::GetColor() const{
		return m_sprite.getColor();
	}

	void Shot::SetColor(sf::Color color) {
		m_sprite.setColor(color);
	}

	bool Shot::IsAvailable() {
		return !m_beingFired;
	}

}