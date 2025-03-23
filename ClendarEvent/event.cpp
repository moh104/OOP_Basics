#include <ctime>
#include "event.hpp"

using namespace std;

Event::Event(const string& i_name , time_t i_start , time_t i_end) : start{i_start} , end{i_end}
{
    set_name(i_name);
    validationTimes(i_start , i_end);
}

string Event::get_name() const noexcept
{
    return name;
}

time_t Event::get_start() const noexcept
{
    return start;
}

time_t Event::get_end() const noexcept
{
    return end;
}

bool Event::isExpired() const noexcept
{
    return end < time(nullptr);
}

void Event::print() const noexcept
{
    cout << "Event: " << name << "\n";
    cout << "Start time: " << ctime(&start);
    cout << "End time: " << ctime(&end);
    cout << "------------------------\n";
}

void Event::set_name(const string& i_name)
{
    if (i_name.empty())
    {
        throw invalid_argument("Event name cannot be empty.");
    }
    name = i_name;
}

void Event::validationTimes(time_t i_start , time_t i_end) const
{
    if (i_start >= i_end)
    {
        throw invalid_argument("Start time must be earlier than end time.");
    }
    if (i_start <= time(nullptr))
    {
        throw invalid_argument("Start time must be in the future.");
    }
    if (i_end <= time(nullptr))
    {
        throw invalid_argument("End time must be in the future.");
    }
}

Event::~Event() noexcept
{
    cout << "Event '" << name << "' has been deleted.\n";
}