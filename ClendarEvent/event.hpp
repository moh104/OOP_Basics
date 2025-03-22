#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
class Event
{
    public:
        Event(const std::string& , time_t , time_t);
        
        [[nodiscard]] std::string get_name() const noexcept;
        [[nodiscard]] time_t get_start() const noexcept;
        [[nodiscard]] time_t get_end() const noexcept;

        [[nodiscard]] bool isExpired() const noexcept;
        void print() const noexcept;

        ~Event() noexcept;
        
    private:
        std::string name;
        time_t start;
        time_t end;
        
        void set_name(const std::string&);
        void validationTimes(time_t , time_t) const;
};

#endif