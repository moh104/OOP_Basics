#include <fstream>
#include "patient.hpp"

using namespace std;

Patient::Patient(const string& i_name, int i_age, double i_bodyTemperature, int i_heartRate, int i_respiratoryRate, int i_bloodPressure)
{
    set_name(i_name);
    set_age(i_age);
    set_bodyTemperature(i_bodyTemperature);
    set_heartRate(i_heartRate);
    set_respiratoryRate(i_respiratoryRate);
    set_bloodPressure(i_bloodPressure);
}

Patient::Patient(const string& i_name, int i_age, double i_bodyTemperature, int i_heartRate, int i_respiratoryRate, int i_bloodPressure , [[maybe_unused]] int 
    Differentiating)
{
    set_name(i_name);
    set_age(i_age);
    if (i_bodyTemperature < 0)
        throw invalid_argument("Body temperature cannot be negative.");
    bodyTemperature = i_bodyTemperature;

    if (i_heartRate < 0)
        throw std::invalid_argument("Heart rate cannot be negative.");
    heartRate = i_heartRate;

    if (i_respiratoryRate < 0)
        throw std::invalid_argument("The respiratory rate cannot be negative.");
    respiratoryRate = i_respiratoryRate;

    if (i_bloodPressure < 0)
        throw std::invalid_argument("Blood pressure cannot be negative.");
    bloodPressure = i_bloodPressure;
}

Patient::~Patient() noexcept
{
    ofstream ofs("patients.dat", ios::app);
    if (ofs.is_open())
    {
        string data = toString();
        string encrypted = xorCipher(data , XOR_KEY);
        ofs << encrypted << '\n';
    }
    else
    {
        std::cerr << "(ERROR) File patients.dat could not be opened for writing." << '\n';
    }
}