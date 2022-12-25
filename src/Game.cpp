#include <SFML/Graphics.hpp>
#include <Game.h>
#include <Player.h>
#include <Walls.h>
#include <string>
#include <iostream>

namespace mt
{
	Game::~Game()
	{
		if (m_window != nullptr)
			delete m_window;
	}

	void Game::set_name(const std::string name)
	{
		m_name = name;
	}

	void Game::set_resolution(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void Game::setup()
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_name);
	}

	void Game::Run()
	{
		float angle = 0;
		float velocity = 0;

		std::cout << "Enter the angle of throw: ";
		std::cin >> angle;

		std::cout << "Enter the force of throw: ";
		std::cin >> velocity;
		
		mt::Player player({ 200, 600 }, 40);
		player.NewVelocity(velocity);
		player.SetAngle(angle);
		player.UpdateVelocity();

		mt::Wall Floor({ 100, 700 }, 1000, 50);
		mt::Wall WallLeft({ 100, 100 }, 50, 600);
		mt::Wall WallRight({ 1050, 100 }, 50, 600);

		sf::Clock timer;

		double t = 0;

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			sf::Time dt = timer.restart();
			t = dt.asMicroseconds() / 1e6;

			player.Move(t);

			m_window->clear();
			m_window->draw(*player.Get());
			m_window->draw(*Floor.Get());
			m_window->draw(*WallLeft.Get());
			m_window->draw(*WallRight.Get());
			m_window->display();

		}
	}
}