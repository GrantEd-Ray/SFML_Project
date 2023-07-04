#pragma once
#include <SFML/Graphics.hpp>
#include <Game.h>
#include <Player.h>
#include <string>
#include <cmath>

namespace mt
{
	class Wall
	{
	private:
		Point m_p;
		float m_len_x, m_len_y;
		sf::RectangleShape* m_rect;
        sf::FloatRect bound;

	public:
		Wall(Point p, float len_x, float len_y);

		~Wall()
		{
			delete m_rect;
		}

		sf::RectangleShape* Get() { return m_rect; }

        sf::FloatRect& get_bound() {return bound;}
	};
}