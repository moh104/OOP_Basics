#include <iomanip>
#include "gps.hpp"

using namespace std;

GPS::GPS(double lat , double lon , const string& name)
{
    set_latitude(lat);
    set_longitude(lon);
    set_locationName(name);
}

GPS::~GPS() noexcept
{
     cout << "GPS object destructed.\nLast position was: \n------------\n";
     cout << "location Name: " << locationName << '\n';
     cout << "Latitude: " << fixed << setprecision(4) << latitude << ", Longitude: " << longitude << std::endl;;
}