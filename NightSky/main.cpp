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