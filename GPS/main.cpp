#include "gps.hpp"

using namespace std;

void menu() noexcept
{
    cout << "\n===== COMMANDS MENU =====\n";
    cout << "1)Show current location\n";
    cout << "2)Update location\n";
    cout << "3)Show menu\n";
    cout << "4)Exit\n";
}

[[nodiscard]] double get_doubleNumber(const string& output)
{
    string input;
    double value;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos{0};
            value = stod(input , &pos);

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid number.\n";
        }
    }
}

[[nodiscard]] int get_intNumber(const string& output)
{
    string input;
    int value;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos{0};
            value = stoi(input , &pos);

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid number.\n";
        }
    }
}

int main()
{
    cout << "Welcome to GPS\n";
    while (true)
    {
        double lat { get_doubleNumber("Enter latitude (-90.0 to 90.0): ") };
        double lon { get_doubleNumber("Enter longitude (-180.0 to 180.0): ") };
        cout << "Enter location name: ";
        string name;
        getline(cin , name);
        try
        {
            GPS gps(lat , lon , name);
            while (true)
            {
                int choice { get_intNumber("Enter command number(enter 3 to see the command menu): ") };
                try
                {
                    if (choice == 1)
                    {
                        gps.print();
                    }
                    else if (choice == 2)
                    {
                        double newLat { get_doubleNumber("Enter new latitude (-90.0 to 90.0): ") };
                        double newLon { get_doubleNumber("Enter new longitude (-180.0 to 180.0): ") };
                        cout << "Enter new location name: ";
                        getline(cin, name);
                        gps.update_location(newLat, newLon, name);
                        cout << "Location updated successfully.\n";
                    }
                    else if (choice == 3)
                    {
                        menu();
                    }
                    else if (choice == 4)
                    {
                        cout << "Exiting program...\n";
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice! Please enter a integer number between 1 and 4.\n";
                    }
                }
                catch (const invalid_argument& e)
                {
                    cout << "(ERROR)" << e.what() << '\n';
                }
            }
            break;
        }
        catch (const invalid_argument& e)
        {
            cout << "(ERROR)" << e.what() << '\n' << "Try again.\n";
        }
    }

    return 0;
}