#include <iostream>
#include "sky.hpp"

using namespace std;

void menu() noexcept
{
    cout << "\n===== NIGHT SKY =====\n";
    cout << "1)Add a Star\n";
    cout << "2)Remove a Star\n";
    cout << "3)Render the Sky\n";
    cout << "4)Show menu\n";
    cout << "5)Exit\n";
}

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

float get_floatNumber(const string& output)
{
    string input;
    float value;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos = 0;
            value = stof(input , &pos);

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

int main()
{
    while(true)
    {
        int posX, posY, Vx, Vy;
        cout << "Enter initial UFO position (x,y)\n";
        posX = get_intNumber("X: ");
        posY = get_intNumber("Y: ");
        cout << "Enter UFO speed (Vx,Vy)\n";
        Vx = get_intNumber("Vx: ");
        Vy = get_intNumber("Vy: ");
        try
        {
            Sky sky(posX, posY, Vx, Vy);
            while (true)
            {
                int choice { get_intNumber("Enter command number(enter 4 to see the command menu): ") };
                try
                {
                    if (choice == 1)
                    {
                        cout << "Enter star position (x,y)\n";
                        int x { get_intNumber("X (0 to 800): ") };
                        int y { get_intNumber("Y (0 to 600): ") };
                        float brightness { get_floatNumber("Enter brightness (1.0 to 5.0): ") };
                        int color { get_intNumber("1)White\n2)Yellow\n3)Gold\n4)pink\nEnter color number: ") };
                        
                        if (color == 1)
                        {
                            sky.add_star(x , y , brightness , WHITE);
                            cout << "Star added successfully.\n";
                        }
                        else if (color == 2)
                        {
                            sky.add_star(x , y , brightness , YELLOW);
                            cout << "Star added successfully.\n";
                        }
                        else if (color == 3)
                        {
                            sky.add_star(x , y , brightness , GOLD);
                            cout << "Star added successfully.\n";
                        }
                        else if (color == 4)
                        {
                            sky.add_star(x , y , brightness , PINK);
                            cout << "Star added successfully.\n";
                        }
                        else
                            cout << "Invalid color number entered.\n";
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter star position to remove (x,y)\n";
                        int x { get_intNumber("X (0 to 600): ") };
                        int y { get_intNumber("Y (0 to 800): ") };
                        sky.remove_star(x , y);
                        cout << "The star was successfully destroyed.\n";
                    }
                    else if (choice == 3)
                    {
                        sky.render();
                    }
                    else if (choice == 4)
                    {
                        menu();
                    }
                    else if (choice == 5)
                    {
                        cout << "Exiting program\n";
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice! Please try again.\n";
                    }
                }
                catch (const invalid_argument& e)
                {
                    cout << "(ERROR)" << e.what() << "\n";
                }
            }
            break;
        }
        catch (const invalid_argument& e)
        {
            cout << "(ERROR)" << e.what() << "\nPlease try again.\n";
        }
    }

    return 0;
}