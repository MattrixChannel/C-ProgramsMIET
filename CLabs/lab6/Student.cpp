#include "Student.h"
#include "iostream"

std::string Student::ToShortString()
{
    return nameSurname.ToShortString() + " " + std::to_string(group);
}

std::string Student::ToString()
{
    return ToShortString();
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

std::istream& operator>> (std::istream& is, Student& stud)
{
    is >> stud.nameSurname;
    std::cout << "Группа: ";
    std::string buf;
    is >> buf;
    if (!Common::is_number(buf)) throw std::string{ "Не число" };
    buf = stud.group;
    return is;
}

std::ostream& operator << (std::ostream& os, Student& stud)
{
    return os << stud.ToString();
}