#include "Teacher.h"

Teacher::Teacher()
{
    Course = "Информатика";
    dep = bms;
}

Teacher::Teacher(Man nameSurname, std::string Course, department dep)
{
    this->nameSurname = nameSurname;
    this->Course = Course;
    this->dep = dep;
}

std::string Teacher::ToShortString()
{
    return nameSurname.ToShortString() + " " + Course + " " + std::to_string(dep);
}
