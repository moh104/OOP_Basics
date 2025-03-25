#include <iostream>
#include <stdexcept>
#include "sky.hpp"

using namespace std;

Sky::Sky(int posX , int posY , int Vx , int Vy)
{
    set_ufoPos(posX , posY);
    set_ufoSpeed(Vx , Vy);
}

void Sky::add_star(int x, int y, float brightness, Color color)
{
    stars.emplace_back(x , y , brightness , color);
}

void Sky::remove_star(int x , int y)
{
    int index = find_index(x , y);
    if (index == -1)
    {
        throw invalid_argument("No stars were found with these coordinates.");
    }

    stars.erase(stars.begin() + index);
}

void Sky::render()
{
    InitWindow(SKY_WIDTH , SKY_HEIGHT , "NIGHT SKY");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        ufoPos.x += ufoSpeed.x;
        ufoPos.y += ufoSpeed.y;
        if (ufoPos.x < UFO_RADIUS_X || ufoPos.x > SKY_WIDTH - UFO_RADIUS_X)
        {
            ufoSpeed.x = -ufoSpeed.x;
            (ufoPos.x < UFO_RADIUS_X) ? (ufoPos.x = UFO_RADIUS_X) : (ufoPos.x = SKY_WIDTH - UFO_RADIUS_X);
        }
        if (ufoPos.y < UFO_RADIUS_Y || ufoPos.y > SKY_HEIGHT - UFO_RADIUS_Y)
        {
            ufoSpeed.y = -ufoSpeed.y;
            (ufoPos.y < UFO_RADIUS_Y) ? (ufoPos.y = UFO_RADIUS_Y) : (ufoPos.y = SKY_HEIGHT - UFO_RADIUS_Y);
        }

        BeginDrawing();
        ClearBackground(DARKBLUE);

        for (const auto& star : stars)
        {
            DrawCircle(star.get_x() , star.get_y() , star.get_brightness() , star.get_color());
        }

        DrawEllipse(static_cast<int>(ufoPos.x) , static_cast<int>(ufoPos.y) , UFO_RADIUS_X , UFO_RADIUS_Y , GRAY);
        DrawCircle(static_cast<int>(ufoPos.x) , static_cast<int>(ufoPos.y - 5) , 8 , LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
}

void Sky::set_ufoPos(int x, int y)
{
    if (x < UFO_RADIUS_X || x > SKY_WIDTH - UFO_RADIUS_X)
    {
        throw invalid_argument("The horizontal position of the UFO is outside the permissible range.(40 to 760)");
    }
    if (y < UFO_RADIUS_Y || y > SKY_HEIGHT - UFO_RADIUS_Y)
    {
        throw invalid_argument("The vertical position of the UFO is outside the permissible range.(10 to 590)");
    }

    ufoPos = {static_cast<float>(x) , static_cast<float>(y)};
}

void Sky::set_ufoSpeed(int x, int y)
{
    if (x > 5 || x < 1)
    {
        throw invalid_argument("The horizontal component of the velocity should be between 1 and 5.");
    }
    if (y > 5 || y < 1)
    {
        throw invalid_argument("The vertical component of the velocity should be between 1 and 5.");
    }

    ufoSpeed = {static_cast<float>(x) , static_cast<float>(y)};
}

int Sky::find_index(int x , int y) const noexcept
{
    for (int i{0} ; (size_t)i < stars.size(); i++)
    {
        if ((stars[i].get_x() == x) && (stars[i].get_y() == y))
        {
            return i;
        }
    }

    return -1;
}

void Sky::DrawEllipse(int posX, int posY, int radiusH, int radiusV, Color color)
{
    for (int y = -radiusV ; y <= radiusV ; y++)
    {
        for (int x = -radiusH ; x <= radiusH ; x++)
        {
            if (((float)(x * x) / (radiusH * radiusH)) + ((float)(y * y) / (radiusV * radiusV)) <= 1.0f)
            {
                DrawPixel(posX + x , posY + y , color);
            }
        }
    }
}

Sky::~Sky() noexcept
{
    cout << "The sky class was destroyed.\n";
}