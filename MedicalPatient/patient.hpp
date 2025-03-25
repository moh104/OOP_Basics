#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>

class Patient
{
    public:
        Patient(const std::string& , int , double , int , int , int);
        Patient(const std::string& , int , double , int , int , int , int);
    
        [[nodiscard]] std::string get_name() const noexcept;
        [[nodiscard]] int get_age() const noexcept;
        [[nodiscard]] double get_bodyTemperature() const noexcept;
        [[nodiscard]] int get_heartRate() const noexcept;
        [[nodiscard]] int get_respiratoryRate() const noexcept;
        [[nodiscard]] int get_bloodPressure() const noexcept;
        
        static std::string xorCipher(const std::string& input , char key) noexcept;
        static constexpr char XOR_KEY{'A'};
        
        ~Patient() noexcept;

    private:
        std::string name;
        int age;
        double bodyTemperature;
        int heartRate;
        int respiratoryRate;
        int bloodPressure;


        void set_name(const std::string&);
        void set_age(int);
        void set_bodyTemperature(double);
        void set_heartRate(int);
        void set_respiratoryRate(int);
        void set_bloodPressure(int);
        
        [[nodiscard]] std::string toString() const noexcept;
};

#endif