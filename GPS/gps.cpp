#include <iomanip>
#include "gps.hpp"

using namespace std;

GPS::GPS(double lat , double lon , const string& name)
{
    set_latitude(lat);
    set_longitude(lon);
    set_locationName(name);
}

void GPS::update_location(double lat , double lon , const string& name)
{
    set_latitude(lat);
    set_longitude(lon);
    set_locationName(name);
}

void GPS::print() const noexcept
{
    std::cout << "Location Name: " << locationName << '\n';
    std::cout << "Latitude: " << fixed << setprecision(4) << latitude << ", Longitude: " << longitude << '\n';
}

void GPS::set_latitude(double lat)
{
    if (lat < -90.0 || lat > 90.0)
    {
        throw invalid_argument("Invalid latitude. Must be between -90 and 90.");
    }
    latitude = lat;
}

void GPS::set_longitude(double lon)
{
    if (lon < -180.0 || lon > 180.0)
    {
        throw invalid_argument("Invalid longitude. Must be between -180 and 180.");
    }
    longitude = lon;
}

void GPS::set_locationName(const string& name)
{
    if (name.empty())
    {
        throw invalid_argument("Location name cannot be empty.");
    }
    locationName = name;
}

GPS::~GPS() noexcept
{
     cout << "GPS object destructed.\nLast position was: \n------------\n";
     cout << "location Name: " << locationName << '\n';
     cout << "Latitude: " << fixed << setprecision(4) << latitude << ", Longitude: " << longitude << std::endl;;
}