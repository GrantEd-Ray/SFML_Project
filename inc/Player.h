#pragma once
#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <Game.h>
#include <string>
#include <cmath>

namespace mt
{
	struct Point
	{
		float x;
		float y;
	};

	class Player
	{
	private:
		Point m_p0;
		float m_v = 0;
		float vx = 0;
		float vy = 0;
		float m_alpha;
		float m_r;
		sf::CircleShape* m_ball;
        sf::FloatRect bound;

	public:
		Player(Point p0, float r)
		{
			m_p0 = p0;
			m_r = r;
			m_ball = new sf::CircleShape(m_r);
			m_ball->setFillColor(sf::Color::Green);
			m_ball->setOrigin(m_r, m_r);
            bound = m_ball->getGlobalBounds();
		}
		~Player()
		{
			delete m_ball;
		}

		void NewVelocity(float v);

		void SetAngle(float alpha);

		void UpdateVelocity();

		void Move(double t);

		sf::CircleShape* Get() { return m_ball; }
	};
}