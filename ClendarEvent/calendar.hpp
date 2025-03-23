#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <vector>
#include "event.hpp"

class Calendar
{
    public:
        explicit Calendar(const std::string&);

        void add_event(const std::string& , time_t , time_t );
        void refresh() noexcept;

        void printEvents() const noexcept;
        void findEvent(time_t) const noexcept;

        ~Calendar() noexcept;
    
    private:
        std::vector <Event> events;
        std::string owner;
};

#endif