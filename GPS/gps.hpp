#ifndef GPS_HPP
#define GPS_HPP

#include <iostream>

class GPS
{
    public:
        GPS(double , double , const std::string&);

        void update_location(double , double , const std::string&);
        void print() const noexcept;

        ~GPS() noexcept;
        
    private:
        double latitude; 
        double longitude;
        std::string locationName; 

        void set_latitude(double);
        void set_longitude(double);
        void set_locationName(const std::string &);
};

#endif