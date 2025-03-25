#ifndef SKY_HPP
#define SKY_HPP

#include <vector>
#include "star.hpp"

class Sky
{
    public:
        Sky(int posX , int posY , int Vx , int Vy);

        void add_star(int x , int y , float brightness , Color color);
        void remove_star(int x , int y);
        void render();
        
        static constexpr int UFO_RADIUS_X{40};
        static constexpr int UFO_RADIUS_Y{10};

        ~Sky() noexcept;
        
    private:
        std::vector<Star> stars;

        Vector2 ufoPos;
        Vector2 ufoSpeed;


        void set_ufoPos(int x, int y);
        void set_ufoSpeed(int x, int y);

        [[nodiscard]] int find_index(int x , int y) const noexcept;
        static void DrawEllipse(int posX, int posY, int radiusH, int radiusV, Color color);
};

#endif