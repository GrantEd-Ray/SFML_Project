#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Walls.h"

namespace mt
{
    mt::Wall* Floor = new mt::Wall({ 100, 700 }, 1000, 50);
    mt::Wall* WallLeft = new mt::Wall({ 100, 100 }, 50, 600);
    mt::Wall* WallRight = new mt::Wall({ 1050, 100 }, 50, 600);

    inline std::vector<mt::Wall*> walls = {WallRight, WallLeft};
    //std::vector<mt::Wall*> floors = {};

    class Game
	{
	private:
		int m_width, m_height;
		std::string m_name;
		sf::RenderWindow* m_window = nullptr;
	
	public:
		Game(){}

		~Game();

		void set_name(const std::string name);

		void set_resolution(int width, int height);

		void setup();

		void Run();
	};
}