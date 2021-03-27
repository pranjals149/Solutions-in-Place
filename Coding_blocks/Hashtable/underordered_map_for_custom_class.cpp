#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }

    bool operator==(const Student &s) const
    {
        return rollno == s.rollno;
    }
};

class HashFn
{
public:
    size_t operator()(const Student &s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};

int main()
{

    unordered_map<Student, int, HashFn> student_map;
    Student s1("Pranjal", "Sri", "10");
    Student s2("Prateek", "Sri", "11");
    Student s3("Rahul", "Sri", "12");
    Student s4("Ramesh", "Sri", "13");

    //add students to hash map
    student_map[s1] = 100;
    student_map[s2] = 110;
    student_map[s3] = 120;
    student_map[s4] = 130;

    for (auto s : student_map)
    {
        cout << s.first.firstname << " " << s.first.rollno << "Marks: " << s.second << endl;
    }
    return 0;
}