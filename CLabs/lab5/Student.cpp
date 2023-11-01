#include "Student.h"

std::string Student::ToShortString()
{
    return (nameSurname.ToShortString() + " " + std::to_string(group));
}

Student::Student()
{
    group = 0;
}

Student::Student(Man namesurname, int group)
{
    this->nameSurname = namesurname;
    this->group = group;
}
