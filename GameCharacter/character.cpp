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

const string& Skill::get_name() const noexcept
{
    return name;
}

int Skill::get_level() const noexcept
{
    return level;
}

void Skill::set_name(const string& i_name)
{
    if (i_name.empty())
    {
        throw invalid_argument("Skill name cannot be empty.");
    }
    name = i_name;
}

void Skill::set_level(int i_level)
{
    if (i_level < MIN_LEVEL || i_level > MAX_LEVEL)
    {
        throw invalid_argument("The skill level must be between 0 and 50.");
    }
    level = i_level;
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