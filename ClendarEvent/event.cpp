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

Event::~Event() noexcept
{
    cout << "Event '" << name << "' has been deleted.\n";
}