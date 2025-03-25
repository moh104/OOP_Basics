#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <vector>
#include "patient.hpp"

class Hospital
{
    public:
        Hospital();

        void add_patient(const std::string& , int , double , int , int , int);
        void print() const noexcept;

        ~Hospital() noexcept;

    private:
        std::vector<Patient> patients; 

        void load();
};

#endif