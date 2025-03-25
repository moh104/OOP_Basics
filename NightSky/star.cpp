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

int Star::get_x() const noexcept
{
    return x;
}

int Star::get_y() const noexcept
{
    return y;
}

float Star::get_brightness() const noexcept
{
    return brightness;
}

Color Star::get_color() const noexcept
{
    return color;
}

void Star::set_x(int x)
{
    if (x < 0 || x > SKY_WIDTH)
    {
        throw invalid_argument("The x coordinate is outside the sky range.");
    }

    this->x = x;
}

void Star::set_y(int y)
{
    if (y < 0 || y > SKY_HEIGHT)
    {
        throw std::invalid_argument("The y coordinate is outside the sky range.");
    }

    this->y = y;
}

void Star::set_brightness(float brightness)
{
    if (brightness < 1.0f || brightness > 5.0f)
    {
        throw std::invalid_argument("Brightness should be between 1.0 and 5.0.");
    }

    this->brightness = brightness;
}

void Star::set_color(Color color) noexcept
{
    this->color = color;
}

Star::~Star() noexcept
{
    cout << "The star with coordinates (" << x << ',' << y << ") disappeared.\n";
}