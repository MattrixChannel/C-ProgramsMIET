// OOPSeminars.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Employee.h"
#include "Company.h"
#include <iostream>



int main()
{

    Company* Companies = new Company[5];

    Companies[0].SetCompanyName("Zero");
    Companies[1].SetCompanyName("One");
    Companies[2].SetCompanyName("Two");
    Companies[3].SetCompanyName("Three");
    Companies[4].SetCompanyName("Four");

    for (int i = 0; i < 5; i++) {
        Companies[i].GetEmployees()[0].SetSurname("0");
        for (int j = 0; j < i; j++) {
            Employee empl;
            Companies[i].AddEmployee(empl);
        }
        for (int j = 1; j < Companies[i].GetNumberOfEmployees(); j++) {
            std::string nam = "Surname" + j;
            Companies[i].GetEmployees()[j].SetSurname(nam);
        }
        std::cout << Companies[i] << std::endl;
    }

    std::cout << "\n\nCompanies where number of employees less or equal 3:\n";
    for (int i = 0; i < 5; i++) {
        if (Companies[i] <= Companies[2]) {
            std::cout << Companies[i] << std::endl;
        }
    }

    delete[] Companies;
}