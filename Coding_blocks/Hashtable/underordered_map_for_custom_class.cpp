#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Student {
    public:
        string firstname;
        string lastname;
        string rollno;

        Student(string f, string l, string no) {
            firstname = f;
            lastname = l;
            rollno = no;
        }
};

int main() {
    Student s1("Pranjal", "Sri", "10");
    Student s2("Pranjal", "Sri", "10");
    Student s3("Pranjal", "Sri", "10");
    Student s4("Pranjal", "Sri", "10");
    return 0;
}