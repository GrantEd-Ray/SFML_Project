#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <Game.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

int main()
{
    mt::Game game;

    game.set_name("Game_1");
    game.set_resolution(1200, 800);
    game.setup();
    game.Run();

    for (int i = 0; i < mt::walls.size(); i++)
        delete mt::walls[i];

    delete mt::Floor;
    
    return 0;
}