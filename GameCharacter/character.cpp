#include <stdexcept>
#include <iostream>
#include "character.hpp"

using namespace std;

int get_intNumber(const string& output)
{
    string input;
    int value;
    
    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos = 0;
            value = stoi(input , &pos);
    
            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a integer number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid integer number.\n";
        }
    }
}

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

void Character::set_name(const string& i_name)
{
    if (i_name.empty())
    {
        throw invalid_argument("Character name cannot be empty.");
    }
    name = i_name;
}

void Character::set_health(int i_health)
{
    if (i_health < MIN_HEALTH || i_health > MAX_HEALTH)
    {
        throw invalid_argument("The level of health must be between 0 and 100.");
    }
    health = i_health;
}

void Character::set_power(int i_power)
{
    if (i_power < MIN_POWER || i_power > MAX_POWER)
    {
        throw invalid_argument("The level of power must be between 0 and 100.");
    }
    power = i_power;
}

string Character::get_name() const noexcept
{
    return name;
}

void Character::add_skill(const string& skillName , int level)
{
    int index{find_index(skillName)};
    if (index != -1)
    {
        skills[index].set_level(level);
        cout << "Skill level '" << skillName << "' updated.\n";
    }
    else
    {
        if (skills.size() == skills.capacity()) [[unlikely]]
        {
            cout << "The skills capacity for character is full. So to create new skills capacity, a new memory with more capacity is created and the previous skills are copied to the new memory and then deleted.\n";
        }
        skills.emplace_back(skillName , level);
        cout << "Skill added successfully.\n";
    }
}

void Character::remove_skill(const std::string& skillName)
{
    int index{find_index(skillName)};
    if (index == -1)
    {
        throw std::invalid_argument("The desired skill was not found.");
    }
    skills.erase(skills.begin() + index);
}

void Character::print() const noexcept
{
    cout << "Name: " << name << "\n";
    cout << "Health: " << health << "\n";
    cout << "Power: " << power << "\n";
    cout << "----------\nSkills:\n";
    if (skills.empty())
    {
        std::cout << "There is no skill.\n";
    }
    else
    {
        for (const auto& skill : skills)
        {
            std::cout << "  " << skill.get_name() << " : lvl " << skill.get_level() << "\n";
        }
    }
    cout << "----------\n";
}

void Character::initialSkills()
{
    int numSkills;
    while (true)
    {
        numSkills = get_intNumber("Specify the number of skills to initialize: ");
        if (numSkills >= 0)
            break;

        cerr << "The number of skills cannot be negative. Please try again.\n";
    }

    for (int i = 0 ; i < numSkills ;)
    {
        cout << "Enter Skill name: ";
        string skillName;
        getline(cin , skillName);
        int level{get_intNumber("Enter Skill level (0 to 50): ")};
        try
        {
            add_skill(skillName , level);
            i++;
        }
        catch(const invalid_argument& e)
        {
            cout << "(ERROR) " << e.what() << "Fix this skill again.\n";
        }
    }
}

int Character::find_index(const string& skillName) const noexcept
{
    int index{0};
    for (const auto& skill : skills)
    {
        if (skill.get_name() == skillName) [[unlikely]]
            return index;
        
        index++;
    }

    return -1;
}

Character::~Character() noexcept
{
    cout << "Character '" << name << "' deleted.\n";
}