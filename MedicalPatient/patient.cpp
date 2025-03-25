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

string Patient::get_name() const noexcept
{
    return name;
}

int Patient::get_age() const noexcept
{
    return age;
}

double Patient::get_bodyTemperature() const noexcept
{
    return bodyTemperature;
}

int Patient::get_heartRate() const noexcept
{
    return heartRate;
}

int Patient::get_respiratoryRate() const noexcept
{
    return respiratoryRate;
}

int Patient::get_bloodPressure() const noexcept
{
    return bloodPressure;
}

string Patient::xorCipher(const string& data , char key) noexcept
{
    string output{data};
    for (char& ch : output)
    {
        ch ^= key;
    }
    return output;
}

void Patient::set_name(const string& i_name)
{
    if (i_name.empty())
    {
        throw invalid_argument("Name cannot be empty.");
    }
    name = i_name;
}

void Patient::set_age(int i_age)
{
    if (i_age < 0)
    {
        throw std::invalid_argument("Age cannot be negative.");
    }
    age = i_age;
}

void Patient::set_bodyTemperature(double i_bodyTemperature)
{
    if (i_bodyTemperature < 0)
        throw invalid_argument("Body temperature cannot be negative.");
    
    if (i_bodyTemperature < 36.0)
        cout << "DANGER: Body temperature (" << i_bodyTemperature << ") is below normal (lower limit: 36.0 C)." << '\n';
    
    else if (i_bodyTemperature > 37.5)
        cout << "DANGER: Body temperature (" << i_bodyTemperature << ") is above normal (upper limit: 37.5 C)." << '\n';
    
    bodyTemperature = i_bodyTemperature;
}

void Patient::set_heartRate(int i_heartRate)
{
    if (i_heartRate < 0)
        throw std::invalid_argument("Heart rate cannot be negative.");
    
    if (i_heartRate < 60)
        cout << "DANGER: Heart rate (" << i_heartRate << ") is below normal (lower limit: 60 bpm)." << '\n';
    
    else if (i_heartRate > 100)
        cout << "DANGER: Heart rate (" << i_heartRate << ") is above normal (upper limit: 100 bpm)." << '\n';
    
    heartRate = i_heartRate;  
}

void Patient::set_respiratoryRate(int i_respiratoryRate)
{
    if (i_respiratoryRate < 0)
        throw std::invalid_argument("The respiratory rate cannot be negative.");
    
    if (age < 1)
    {
        if (i_respiratoryRate < 30)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is below normal (lower limit: 30)." << '\n';
        
        else if (i_respiratoryRate > 60)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is above normal (upper limit: 60)." << '\n';
    }
    else if (age >= 1 && age <= 5)
    {
        if (i_respiratoryRate < 24)
            cout << "DANGER: Respiratory rate relative to age (" << i_respiratoryRate << ") is below normal (lower limit: 24)." << '\n';
        
        else if (i_respiratoryRate > 40)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is above normal (upper limit: 40)." << '\n';
    }
    else if (age >= 6 && age <= 12)
    {
        if (i_respiratoryRate < 18)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is below normal (lower limit: 18)." << '\n';
        
        else if (i_respiratoryRate > 30)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is above normal (upper limit: 30)." << '\n';
    }
    else if (age >= 13 && age<= 18)
    {
        if (i_respiratoryRate < 12)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is less than normal (lower limit: 12)." << '\n';
    
        else if (i_respiratoryRate > 20)
            cout << "DANGER: respiratory rate relative to age (" << i_respiratoryRate << ") is above normal (upper limit: 20)." << '\n';
    }
    else
    {
        if (i_respiratoryRate < 12)
            cout << "DANGER: Adult respiratory rate (" << i_respiratoryRate << ") is less than normal (lower limit: 12)." << '\n';

        else if (i_respiratoryRate > 20)
            cout << "DANGER: Adult respiratory rate (" << i_respiratoryRate << ") is above normal (upper limit: 20)." << '\n';
    }
    
    respiratoryRate = i_respiratoryRate;
}

void Patient::set_bloodPressure(int i_bloodPressure)
{
    if (i_bloodPressure < 0)
        throw std::invalid_argument("Blood pressure cannot be negative.");

    if (i_bloodPressure < 80)
        std::cerr << "DANGER: Blood pressure (" << i_bloodPressure << ") is below the normal limit (lower limit: 80)." << '\n';

    else if (i_bloodPressure > 120)
        cout << "DANGER: Blood pressure (" << i_bloodPressure << ") is above normal (upper limit: 120)." << '\n';

    bloodPressure = i_bloodPressure;
}

string Patient::toString() const noexcept
{
    return name + "," + to_string(age) + "," + to_string(bodyTemperature) + "," + to_string(heartRate) + "," +
        to_string(respiratoryRate) + "," + to_string(bloodPressure);
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