#include <iostream>
#include "game.hpp"

using namespace std;

void menu()
{
    cout << "\nMENU:\n";
    cout << "1) Add Character\n";
    cout << "2) Remove Character\n";
    cout << "3) Show Character Attributes\n";
    cout << "4) Print All Characters\n";
    cout << "5) Modify Character Attributes\n";
    cout << "6) Add Skill to Character\n";
    cout << "7) Remove Skill from Character\n";
    cout << "8)Show commands menu\n";
    cout << "9) Exit\n";
}
int main()
{
    Game game;
    while(true)
    {
        int choice { get_intNumber("Enter command number(enter 8 to see the command menu): ") };
        try
        {
            if (choice == 1)
            {
                string name;
                cout << "Enter the character name: ";
                getline(cin , name);
                int health { get_intNumber("Enter the character's health (0 to 100): ") };
                int power { get_intNumber("Enter the character's power (0 to 100):") };
                game.add_character(name , health , power);
            }
            else if (choice == 2)
            {
                cout << "Enter the name of the character to remove: ";
                string name;
                getline(cin, name);
                game.remove_character(name);
                cout << "Character removed successfully.\n";
            }
            else if (choice == 3)
            {
                cout << "Enter the name of the character to see its Attributes: ";
                string name;
                getline(cin, name);
                game.showCharacterAttr(name);
            }
            else if (choice == 4)
            {
                game.print();
            }
            else if (choice == 5)
            { 
                cout << "Enter the name of the character to modify: ";
                string name;
                getline(cin, name);
                game.modifyCharacter(name);
                cout << "The character was successfully changed.\n";
            }
            else if (choice == 6)
            { 
                cout << "Enter the name of the character: ";
                string name;
                getline(cin, name);
                game.add_charSkill(name);
            }
            else if (choice == 7)
            { 
                cout << "Enter the name of the character: ";
                string name;
                getline(cin, name);
                game.remove_charSkill(name);
            }
            else if (choice == 8)
            {
                menu();
            }
            else if (choice == 9)
            {
                cout << "Exiting the game.\n";
                break;
            }
            else
            {
                cout << "Invalid option! Please enter a number between 1 and 9.\n";
            }
        }
        catch(const invalid_argument& e)
        {
            cerr << "(ERROR) " << e.what() << '\n';
        }
    }
    
    return 0;
}