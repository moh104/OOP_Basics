#include <iostream>
#include "calendar.hpp"

using namespace std;


Calendar::Calendar(const string& ownerName) : owner(ownerName)
{
    events.reserve(100);
    cout << "New calendar created for: '" << owner << "'\n";
}

void Calendar::add_event(const string& name, time_t start, time_t end)
{  
    for (const auto& event : events)
    {
        if((start < event.get_end()) && (end > event.get_start()))
        {
            throw invalid_argument("The desired event interferes with other events.");
        }
    }
    if (events.size() == events.capacity()) [[unlikely]]
    {
        cout << "The calendar capacity for events is full. So to create new events, a new memory with more capacity is created and the previous events are copied to the new memory and then deleted.\n";
    }
    events.emplace_back(name , start , end);
    cout << "Event '" << name << "' added successfully.\n";
}

void Calendar::refresh() noexcept
{
    auto it = events.begin();

    while (it != events.end())
    {
        if (it->isExpired())
        {
            it = events.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void Calendar::printEvents() const noexcept
{
    if (events.empty())
    {
        cout << "There are no events in the calendar.\n";
        return;
    }
    cout << "EVENTS:\n";
    for (const auto& event : events)
    {
        event.print();
    }
}

void Calendar::findEvent(time_t time) const noexcept
{
    for (const auto& event : events)
    {
        if (event.get_start() <= time && event.get_end() >= time) [[unlikely]]
        {
            cout << "Event: " << event.get_name() << "\n";
            return;
        }
    }

    cout << "There are no events on this date.\n";
}

Calendar::~Calendar() noexcept
{
    cout << "The calendar has been deleted.\n";
}