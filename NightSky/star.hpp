#ifndef STAR_HPP
#define STAR_HPP

#include <raylib.h>

constexpr int SKY_WIDTH{800};
constexpr int SKY_HEIGHT{600};

class Star
{
    public:
        Star(int x , int y , float brightness , Color color);

        [[nodiscard]] int get_x() const noexcept;
        [[nodiscard]] int get_y() const noexcept;
        [[nodiscard]] float get_brightness() const noexcept;
        [[nodiscard]] Color get_color() const noexcept;

        ~Star() noexcept;

    private:
        int x;
        int y;
        float brightness;
        Color color;

        void set_x(int x);
        void set_y(int y);
        void set_brightness(float brightness);
        void set_color(Color color) noexcept;
};

#endif