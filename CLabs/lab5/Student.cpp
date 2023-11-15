#include "Student.h"
#include "iostream"

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

void Student::GetInfo(std::vector<Student> db)
{
    std::cout << "Студенты: \nИмя Фамилия Группа\n";
    for (int i = 0; i < db.size(); i++) {
        std::cout << db[i].nameSurname.ToShortString() << " " << db[i].group << std::endl;
    }
}

std::string const Student::GetNameFam()
{
    return nameSurname.ToShortString();
}

const bool Student::operator == (Man manr) {
    if (nameSurname.ToShortString() == manr.ToShortString()) return true;
    else return false;
}

std::istream& operator>> (std::istream& is, Student& stud)
{
    is >> stud.nameSurname;
    std::cout << "Группа: ";
    is >> stud.group;
    return is;
}