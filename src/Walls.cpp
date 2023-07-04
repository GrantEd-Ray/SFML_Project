#include <SFML/Graphics.hpp>
#include <Game.h>
#include <Player.h>
#include <Walls.h>
#include <string>
#include <cmath>

namespace mt
{

	Wall::Wall(Point p, float len_x, float len_y)
	{
		m_p = p;
		m_len_x = len_x;
		m_len_y = len_y;
		m_rect = new sf::RectangleShape(sf::Vector2f(m_len_x, m_len_y));
		float x = m_p.x;
		float y = m_p.y;
		m_rect->setPosition(x, y);
        bound = m_rect->getGlobalBounds();
	}
}