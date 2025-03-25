#include <fstream>
#include <iostream>
#include "hospital.hpp"

using namespace std;

void menu() noexcept
{
    cout << "\n=== HOSPITAL MANAGEMENT SYSTEM ===\n";
    cout << "1)Add new patient\n";
    cout << "2)Display the list of patients\n";
    cout << "3)Show menu\n";
    cout << "4)EXIT\n";
}

[[nodiscard]] double get_doubleNumber(const string& output)
{
    string input;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos{0};
            double value { stod(input , &pos) };

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a double number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid double number.\n";
        }
    }
}

[[nodiscard]] int get_intNumber(const string& output)
{
    string input;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos{0};
            int value { stoi(input , &pos) };

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