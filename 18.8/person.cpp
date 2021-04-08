#include "person.h"

person::person(void) {
    name = "";
    age = 0;
}

person::~person(void) = default;

person::person(string n, int a) {
    name = n;
    age = a;
}

person::person(const person &person) {
    name = person.name;
    age = person.age;
}

person &person::operator=(const person &p) {
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}


void person::show() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << endl;
}

void person::input() {
    cout << "Name? "; cin >> name;
    cout << "Age? "; cin >> age;
}
