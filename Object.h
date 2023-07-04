#pragma once

#include "Player.h"

enum class ObjectType
{
    Wall,
    Obstacle,
    Player
};

class Object
{
protected:
    mt::Point m_p;
    ObjectType m_type;
public:
    Object(mt::Point p)
    {

    }
};

class Wall : public Object
{
protected:
    sf::RectangleShape m_shape;
public:
    Wall(mt::Point p) : Object(p)
    {
        m_type = ObjectType::Wall;
    }
};