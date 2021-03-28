#include "student.h"

using namespace std;

student::student(void) : person() {
    year = 0;
}

student::~student(void) {}

student::student(string n, int a, int y) : person(n, a) {
    year = y;
}

student::student(const student &s) {
    name = s.name;
    age = s.age;
    year = s.year;
}

student &student::operator=(const student &s) {
    if (&s == this) {
        return *this;
    }
    name = s.name;
    age = s.age;
    year = s.year;
    return *this;
}

void student::show() {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\nYear: " << year;
    cout << endl;
}

istream &operator>>(istream &in, student &s) {
    cout << "\nName: ";
    in >> s.name;
    cout << "\nAge: ";
    in >> s.age;
    cout << "\nYear: ";
    in >> s.year;
    return in;
}

ostream &operator<<(ostream &out, const student &s) {
    out << "\nName: " << s.name;
    out << "\nAge: " << s.age;
    out << "\nYear: " << s.year;
    return out;
}