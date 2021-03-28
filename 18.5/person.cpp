#include "person.h"

person::person() {
    name = "";
    age = 0;
}

person::~person(void) = default;

person::person(string name, int age) {
    this->name = name;
    this->age = age;
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

istream &operator>>(istream &in, person &p) {
    cout << "\nName: ";
    in >> p.name;
    cout << "\nAge: ";
    in >> p.age;
    return in;
}

ostream &operator<<(ostream &out, const person &p) {
    out << "\nName: " << p.name;
    out << "\nAge: " << p.age;
    out << endl;
    return out;
}

void person::show() {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << endl;
}