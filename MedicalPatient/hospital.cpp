#include <fstream>
#include <iomanip>
#include "hospital.hpp"

using namespace std;

Hospital::Hospital()
{
    patients.reserve(50);
    cout << "The hospital was created and the information was decrypted.\n";
    load();
}

Hospital::~Hospital() noexcept
{
    cout << "The hospital was destroyed and the information was encrypted.\n";
}