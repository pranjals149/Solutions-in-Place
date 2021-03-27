//Given a person , numbers can he/she have
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    unordered_map<string, vector<string>> phonebook;

    phonebook["rahul"].push_back("9110");
    phonebook["rahul"].push_back("9120");
    phonebook["rahul"].push_back("9130");
    phonebook["rahul"].push_back("9140");

    phonebook["kajal"].push_back("8810");
    phonebook["kajal"].push_back("8820");
    phonebook["kajal"].push_back("8830");
    phonebook["kajal"].push_back("8840");

    for (auto p : phonebook)
    {
        cout << "Name: " << p.first << "->";

        for (string s : p.second)
        {
            cout << s << ", "
        }

        cout << endl;
    }

    string name;
    cin >> name;

    if (phonebook.count(name) == 0) {
        cout << "Not present";
    } else {
        for (string s : phonebook[name]) {
            cout << s << endl;
        }
    }

    return 0;
}