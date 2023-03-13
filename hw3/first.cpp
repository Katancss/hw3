#include <iostream>
#include <string>
#include <vector>
#include "json.h"

using namespace std;

using json = nlohmann::json;

struct Person {
public:
    string name;
    int age;
    double height;
    bool is_married;

    
    friend istream& operator>>(istream& in, Person& person) {
        cout << "Enter name: ";
        getline(in, person.name);

        cout << "Enter age: ";
        in >> person.age;
        in.ignore();

        cout << "Enter height: ";
        in >> person.height;
        in.ignore();

        cout << "Enter marital status (1 - married, 0 - not married): ";
        in >> person.is_married;
        in.ignore();

        return in;
    }
};

int main() {
    Person p1, p2;

    cout << "Enter data for person 1:" << endl;
    cin >> p1;

    cout << "Enter data for person 2:" << endl;
    cin >> p2;

    json person1;
    person1["name"] = p1.name;
    person1["age"] = p1.age;
    person1["height"] = p1.height;
    person1["is_married"] = p1.is_married;

    json person2;
    person2["name"] = p2.name;
    person2["age"] = p2.age;
    person2["height"] = p2.height;
    person2["is_married"] = p2.is_married;

    cout << "Person 1 data in JSON format:" << endl;
    cout << person1 << endl;

    cout << "Person 2 data in JSON format:" << endl;
    cout << person2 << endl;

    return 0;
}
