#include <iostream>
#include "calendar.hpp"

using namespace std;


Calendar::Calendar(const string& ownerName) : owner(ownerName)
{
    events.reserve(100);
    cout << "New calendar created for: '" << owner << "'\n";
}

Calendar::~Calendar() noexcept
{
    cout << "The calendar has been deleted.\n";
}