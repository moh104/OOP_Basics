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

Game::~Game() noexcept
{
    cout << "The game was destroyed.\n";
}