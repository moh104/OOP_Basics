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

void Hospital::add_patient(const std::string& name, int age, double bodyTemperature, int heartRate, int respiratoryRate, int bloodPressure)
{
    if (patients.size() == patients.capacity()) [[unlikely]]
    {
        cout << "The hospital capacity for patients is full. So to create new patients, a new memory with more capacity is created and the previous patients are copied to the new memory and then deleted.\n";
    }
    patients.emplace_back(name, age, bodyTemperature, heartRate, respiratoryRate, bloodPressure);
}

void Hospital::print() const noexcept
{
    if (patients.empty()) [[unlikely]]
    {
        cout << "There are no patients in the hospital.\n";
        return;
    }
    for (const auto& patient : patients)
    {
        std::cout << "Name: " << patient.get_name() << '\n'
        << "Age: " << patient.get_age() << '\n'
        << "Body temperature: " << patient.get_bodyTemperature() << " C" << '\n'
        << "Heart rate: " << patient.get_heartRate() << " bpm" << '\n'
        << "Respiratory rate: " << patient.get_respiratoryRate() << '\n'
        << "Blood pressure: " << patient.get_bloodPressure() << '\n'
        << "-------------------\n";
    }
}

void Hospital::load()
{
    ifstream ifs("patients.dat");
    if (!ifs.is_open()) [[unlikely]]
    {
        return;
    }

    string line;
    while (getline(ifs , line))
    {
        string decrypted = Patient::xorCipher(line, Patient::XOR_KEY);
        string items[6];
        size_t start = 0;
        size_t space = 0;
        for (int i = 0 ; i < 5 ; i++)
        {
            space = decrypted.find(',' , start);
            items[i] = decrypted.substr(start , space - start);
            start = space + 1;
        }
        items[5] = decrypted.substr(start);
        patients.emplace_back(items[0] , stoi(items[1]) , stod(items[2]) , stoi(items[3]) , stoi(items[4]) , stoi(items[5]) , 1);
    }
}

Hospital::~Hospital() noexcept
{
    cout << "The hospital was destroyed and the information was encrypted.\n";
}