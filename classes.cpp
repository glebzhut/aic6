#include "classes.h"

using namespace std;

int STUDENT_ID = 1;
int GROUP_ID = 1;

Student::Student() : name_("New student " + to_string(STUDENT_ID++)) {};
Student::Student(const string& name) : name_(name) { STUDENT_ID++; };

string Student::GetName() const
{
    return name_;
}

//Constructors
Group::Group() : name_("NULL") {};
Group::Group(const string& name) : name_(name) { GROUP_ID++; };
Group::Group(const vector<Student>& students) : name_("New group " + to_string(GROUP_ID++)), students_(students) {};
Group::Group(const string& name, const vector<Student>& students) : name_(name), students_(students) { GROUP_ID++; };

//Method for setting list of students
void Group::SetStudents(const vector<Student>& students)
{
    this->students_ = students;
}

//Method for adding new student
void Group::AddStudents(const Student& student)
{
    students_.insert(students_.end(), student);
}

//Method for adding list of students
void Group::AddStudents(const vector<Student>& students)
{
    students_.insert(students_.end(), students.begin(), students.end());
}

//Method for getting name of group
string Group::GetName() const
{
    return name_;
}

//Method for getting list of students
vector<Student> Group::GetStudents() const
{
    return students_;
}

ostream& operator<<(ostream& os, const Student& student)
{
    os << "Student: " << student.GetName();
    return os;
}

ostream& operator<< (ostream& os, const Group& m)
{
    os << "Group: " << m.GetName() << "(" << m.GetStudents() << ")";
    return os;
}

//overloads comparison operators for students
bool operator>(const Student& lhs, const Student& rhs)
{
    return lhs.GetName() > rhs.GetName();
}

bool operator<(const Student& lhs, const Student& rhs)
{
    return lhs.GetName() < rhs.GetName();
}

bool operator>=(const Student& lhs, const Student& rhs)
{
    return lhs.GetName() >= rhs.GetName();
}

bool operator<=(const Student& lhs, const Student& rhs)
{
    return lhs.GetName() <= rhs.GetName();
}

bool operator==(const Student& lhs, const Student& rhs)
{
    return lhs.GetName() == rhs.GetName();
}

bool operator!=(const Student& lhs, const Student& rhs)
{
    return lhs.GetName() != rhs.GetName();
}

//overloads comparison operators for group
bool operator>(const Group& lhs, const Group& rhs)
{
    return lhs.GetName() > rhs.GetName();
}

bool operator<(const Group& lhs, const Group& rhs)
{
    return lhs.GetName() < rhs.GetName();
}

bool operator>=(const Group& lhs, const Group& rhs)
{
    return lhs.GetName() >= rhs.GetName();
}

bool operator<=(const Group& lhs, const Group& rhs)
{
    return lhs.GetName() <= rhs.GetName();
}

bool operator==(const Group& lhs, const Group& rhs)
{
    return lhs.GetName() == rhs.GetName();
}

bool operator!=(const Group& lhs, const Group& rhs)
{
    return lhs.GetName() != rhs.GetName();
}


//Function for parsing line into different students
vector<Student> Parse(const string& s)
{
    vector<Student> res;
    stringstream s1(s);
    string word;
    while (getline(s1, word))
    {
        res.push_back(Student(word));
    }
    return res;
}