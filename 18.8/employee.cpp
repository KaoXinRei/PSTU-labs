#include "employee.h"

employee::employee(void) : person() {
    salary = 0.0;
    position = "";
}

employee::~employee(void) {
}

void employee::show() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << "Position: " << position << endl;
    cout << endl;
}

void employee::input() {
    cout << "Name? "; cin >> name;
    cout << "Age? "; cin >> age;
    cout << "Salary? "; cin >> salary;
    cout << "Position? "; cin >> position;
}

employee::employee(string n, int a, double s, string p) : person(n, a) {
    salary = s;
    position = p;
}

employee::employee(const employee & e) {
    name = e.name;
    age = e.age;
    salary = e.salary;
    position = e.position;
}

employee &employee::operator=(const employee &e) {
    if (&e == this){
        return *this;
    }
    name = e.name;
    age = e.age;
    salary = e.salary;
    position = e.position;
    return *this;
}
