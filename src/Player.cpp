#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <Game.h>
#include <Player.h>
#include <string>
#include <cmath>

const float g = -9.8;

namespace mt
{
	void Player::NewVelocity(float v)
	{
		m_v = v;
	}

	void Player::SetAngle(float alpha)
	{
		m_alpha = alpha;
	}

	void Player::UpdateVelocity()
	{
		vx = m_v * cos(m_alpha * M_PI / 180);
		vy = m_v * sin(m_alpha * M_PI / 180);

	}

	void Player::Move(double t)
	{
		float x = m_p0.x + vx * t;
		float y = m_p0.y - vy * t;
		m_ball->setPosition(x, y);

		m_p0.x = x;
		m_p0.y = y;
		vy = vy + g * t;
        bound = m_ball->getGlobalBounds();

		bool change_x = false;
		bool change_y = false;

		/*if ((x < 150 + m_r || x > 1050 - m_r) && (change_x == false))
		{
			vx = -vx * 0.9;
            vy *= 0.9;
			change_x = true;
			change_y = false;
		}

		if ((y > 700 - m_r) && (change_y == false))
		{
			vy = -vy;
            vy *= 0.9;
            vx *= 0.9;
			change_y = true;
			change_x = false;
		}*/

        for (int i = 0; i < mt::walls.size(); i++)
        {
            if (bound.intersects(mt::walls[i]->get_bound()) && change_x == false)
            {
                vx = -vx * 0.9;
                vy *= 0.9;
                change_x = true;
                change_y = false;
            }

            if (!(bound.intersects(mt::walls[i]->get_bound())))
                change_x = false;
        }

        if (bound.intersects(mt::Floor->get_bound()) && change_y == false)
        {
            vy = -vy * 0.9;
            vx *= 0.9;
            change_y = true;
            change_x = false;
        }

        if (!(bound.intersects(mt::Floor->get_bound())))
            change_y = false;

		if (vy < 0.01)
		{
			change_y = false;
		}

		if (x > 500 && x < 600)
		{
			change_x = false;
		}

	}
}