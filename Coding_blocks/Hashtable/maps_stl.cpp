#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    map<string, int> m;

    //insert objects in map
    m.insert(make_pair("Mango", 100));
    //another method
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    //another
    m["banana"] = 20;

    //Searching in map
    string fruit;
    cin >> fruit;

    //Update the price in map
    m[fruit] += 22;

    auto it = m.find(fruit);
    if (it != m.end())
    {
        cout << "Price of " << fruit << m[fruit] << endl;
    }
    else
    {
        cout << "Fruit is not present" << endl;
    }

    // Erase an object in map
    m.erase(fruit);

    //another way to find a key
    // maps stores unique key only once
    //to check whether the key is present inside key or not, count function can be used alternatively to find function
    if (m.count(fruit))
    {
        cout << "Price of" << fruit << m[fruit] << endl;
    }

    m["lichi"] = 60;
    m["pineapple"] = 80;

    //Iterate over all the key value pairs
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << "and" << it->second << endl;
    }

    //forEach loop
    for (auto p : m)
    {
        cout << p.first << ":" << p.second << endl;
    }

    return 0;
}