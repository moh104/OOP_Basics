#include <iostream>
#include "game.hpp"

using namespace std;

Game::Game()
{
    characters.reserve(50);
    int characterCount;
    while (true)
    {
        characterCount = get_intNumber("Specify the number of characters to initialize: ");
        if (characterCount >= 0)
            break;

        cerr << "The number of character cannot be negative. Please try again.\n";
    }
    for (int i = 0; i < characterCount;)
    {
        string name , strHealth;
        cout << "Enter the character " << i + 1 << " name: ";
        getline(cin , name);
        int health { get_intNumber("Enter the character's health (0 to 100): ") };
        int power { get_intNumber("Enter the character's power (0 to 100):") };
        try
        {
            add_character(name , health , power);
            i++;
        }
        catch (const invalid_argument& e)
        {
            cout << "(ERROR) " << e.what() << "\nPlease try again.\n";
        }
    }
}

void Game::add_character(const string& name , int health , int power)
{
    int index { find_index(name) };
    if (index != -1)
    {
        characters[index].set_health(health);
        characters[index].set_power(power);
        characters[index].initialSkills();
        cout << "Character '" << name << "' updated.\n";
    }
    else
    {
        if (characters.size() == characters.capacity()) [[unlikely]]
        {
            cout << "The characters capacity for events is full. So to create new characters capacity, a new memory with more capacity is created and the previous characters are copied to the new memory and then deleted.\n";
        }
        characters.emplace_back(name , health , power);
        cout << "Character '" << name << "' added.\n";
    }
}

void Game::remove_character(const std::string& name)
{
    int index { find_index(name) };
    if (index == -1)
    {
        throw invalid_argument("The desired character was not found.");
    }
    characters.erase( characters.begin() + index);
}

void Game::print() const noexcept
{
    if (characters.empty())
    {
        std::cout << "There are no characters in the game.\n";
        return;
    }
    for (const auto& character : characters)
    {
        character.print();
        cout << "==============================\n";
    }
}

void Game::showCharacterAttr(const string& name) const noexcept
{
    int index { find_index(name) };
    if (index != -1)
    {
        characters[index].print();
    }
    else
    {
        cout << "Character not found.\n";
    }
}

void Game::modifyCharacter(const string& name)
{
    int index { find_index(name) };
    if (index == -1)
    {
        throw invalid_argument("Character not found.");
    }

    cout << "Choose attribute number to modify:\n";
    cout << "1)Name\n";
    cout << "2)Health\n";
    cout << "3)Power\n";
    int attrChoice { get_intNumber("Enter your choice: ") };
    if (attrChoice == 1)
    {
        string name;
        cout << "Enter the character name: ";
        getline(cin , name);
        characters[index].set_name(name);
    } 
    else if (attrChoice == 2)
    {
        int health { get_intNumber("Enter the character's health (0 to 100): ") };
        characters[index].set_health(health);
    } 
    else if (attrChoice == 3)
    {
        int power { get_intNumber("Enter the character's power (0 to 100):") };
        characters[index].set_power(power);
    } 
    else
    {
        throw invalid_argument("Invalid choice.");
    }
}

void Game::add_charSkill(const std::string& name)
{
    int index { find_index(name) };
    if (index == -1)
    {
        throw invalid_argument("Character not found.");
    }
    cout << "Enter skill name: ";
    string skillName;
    getline(cin, skillName);
    int level { get_intNumber("Enter skill level (0-50): ") };
    characters[index].add_skill(skillName , level);
}

void Game::remove_charSkill(const string& name)
{
    int index { find_index(name) };
    if (index == -1)
    {
        throw invalid_argument("Character not found.");
    }
    cout << "Enter the name of the skill to remove: ";
    string skillName;
    getline(cin, skillName);
    characters[index].remove_skill(skillName);
}

int Game::find_index(const string& characterName) const noexcept
{
    int index{0};
    for (const auto& character : characters)
    {
        if (character.get_name() == characterName)
            return index;

        index++;
    }

    return -1;
}

Game::~Game() noexcept
{
    cout << "The game was destroyed.\n";
}