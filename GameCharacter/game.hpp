#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"

class Game
{
    public:
        Game();

        void add_character(const std::string& , int , int);
        void remove_character(const std::string&);
        void print() const noexcept;
        void showCharacterAttr(const std::string&) const noexcept;
        void modifyCharacter(const std::string&);
        void add_charSkill(const std::string&);
        void remove_charSkill(const std::string&);

        ~Game() noexcept;
        
    private:
        std::vector<Character> characters;
        
        int find_index(const std::string&) const noexcept;

};

#endif