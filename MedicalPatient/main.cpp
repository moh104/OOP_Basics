#include <fstream>
#include <iostream>
#include "hospital.hpp"

using namespace std;

void menu() noexcept
{
    cout << "\n=== HOSPITAL MANAGEMENT SYSTEM ===\n";
    cout << "1)Add new patient\n";
    cout << "2)Display the list of patients\n";
    cout << "3)Show menu\n";
    cout << "4)EXIT\n";
}

[[nodiscard]] double get_doubleNumber(const string& output)
{
    string input;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos{0};
            double value { stod(input , &pos) };

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a double number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid double number.\n";
        }
    }
}

[[nodiscard]] int get_intNumber(const string& output)
{
    string input;

    while (true)
    {
        cout << output;
        getline(cin , input);
        try
        {
            size_t pos{0};
            int value { stoi(input , &pos) };

            if (pos == input.size())
            {
                return value;
            }
            else
            {
                cout << "Invalid input! Please enter only a integer number without extra characters.\n";
            }
        }
        catch(...)
        {
            cout << "Invalid input! Please enter a valid integer number.\n";
        }
    }
}

int main()
{
    cout << "Welcome to HOSPITAL SYSTEM\n";
    Hospital hospital;
    while (true)
    {
        int choice { get_intNumber("Enter command number(enter 3 to see the command menu): ") };
        try
        {
            switch(choice)
            {
                case 1:
                {
                    cout << "The patient's name: ";
                    string name;
                    getline(cin , name);
                    int age { get_intNumber("Patient age: ") };
                    double bodyTemperature { get_doubleNumber("The patient's body temperature(C):") };
                    int heartRate { get_intNumber("The patient's heart rate(bpm): ") };
                    int respiratoryRate { get_intNumber("The patient's respiratory rate: ") };
                    int bloodPressure { get_intNumber("The patient's blood pressure: ") };
                    hospital.add_patient(name, age, bodyTemperature, heartRate, respiratoryRate, bloodPressure);
                    cout << "Patient added successfully.\n";
                    break;
                }

                case 2:
                    cout << "LIST OF PATIENTS\n";
                    hospital.print();
                    break;

                case 3:
                    menu();
                    break;

                case 4:
                {
                    cout << "Exit the program.\n";
                    ofstream ofs("patients.dat");
                    ofs.close();
                    return 0;
                }
                
                default:
                    cout << "Invalid choice! Please enter a integer number between 1 and 4.\n";
            }
        }
        catch(const invalid_argument& e)
        {
            cerr << "(ERROR) " << e.what() << '\n';
        }
    }
}