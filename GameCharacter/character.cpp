#include <stdexcept>
#include <iostream>
#include "character.hpp"

using namespace std;

// Skill

Skill::Skill(const string& i_name , int i_level)
{
    set_name(i_name);
    set_level(i_level);
}

Skill::~Skill() noexcept
{
    cout << "Skill '" << name << "' was removed.\n";
}

// Character

Character::Character(const string& i_name , int i_health , int i_power)
{
    skills.reserve(50);
    set_name(i_name);
    set_health(i_health);
    set_power(i_power);
    initialSkills();
}

Character::~Character() noexcept
{
    cout << "Character '" << name << "' deleted.\n";
}