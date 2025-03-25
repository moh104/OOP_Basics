#include <iostream>
#include <stdexcept>
#include "star.hpp"

using namespace std;

Star::Star(int x , int y , float brightness , Color color)
{
    set_x(x);
    set_y(y);
    set_brightness(brightness);
    set_color(color);
}

Star::~Star() noexcept
{
    cout << "The star with coordinates (" << x << ',' << y << ") disappeared.\n";
}