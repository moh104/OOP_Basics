#include <iostream>
#include <stdexcept>
#include "sky.hpp"

using namespace std;

Sky::Sky(int posX , int posY , int Vx , int Vy)
{
    set_ufoPos(posX , posY);
    set_ufoSpeed(Vx , Vy);
}

Sky::~Sky() noexcept
{
    cout << "The sky class was destroyed.\n";
}