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