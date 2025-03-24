#include <iostream>
#include <ctime>
#include "calendar.hpp"

using namespace std;

int isIntNumber(string input)
{
    int value;

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
            throw invalid_argument("Invalid number entered.");
        }
    }
    catch(...)
    {
        throw invalid_argument("Invalid number entered.");
    }
}

void menu() noexcept
{
    cout << "\nCMMANDS MENU\n";
    cout << "1)ADD EVENT\n";
    cout << "2)REFRESH\n";
    cout << "3)PRINT EVENTS\n";
    cout << "4)SHOW EXISTING EVENTS AT A SPECIFIC TIME\n";
    cout << "5)SHOW COMMANDS MENU\n";
    cout << "6)EXIT\n";
}

[[nodiscard]] time_t input_time(const string& output)
{
    cout << "Time format must be(From 1970-01-01 onwards): YYYY-MM-DD HH:MM\n";
    cout << output;
    tm tm{};
    string input;
    getline(cin, input);
    if (input.size() != 16 || input[4] != '-' || input[7] != '-' || input[10] != ' ' || input[13] != ':')
    {
        throw std::invalid_argument("Invalid time format. Must be: YYYY-MM-DD HH:MM");
    }
    tm.tm_year = isIntNumber(input.substr(0, 4)) - 1900;
    tm.tm_mon = isIntNumber(input.substr(5, 2)) - 1;
    tm.tm_mday = isIntNumber(input.substr(8, 2));
    tm.tm_hour = isIntNumber(input.substr(11, 2));
    tm.tm_min = isIntNumber(input.substr(14, 2));
    time_t timeResult{mktime(&tm)};
    if (timeResult == -1)
    {
        throw std::invalid_argument("Invalid date entered.");
    }

    return timeResult;
}