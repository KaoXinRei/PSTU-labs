#include <iostream>
#include "person.h"
#include "student.h"
using namespace std;

void f1(person& p) {
    p.set_name("Vlad");
    cout << p;
}

person f2() {
    student s("Anna", 20, 2016);
    return s;
}

int main()
{
    person a;
    cin >> a;
    cout << a;
    person b("Petr", 30);
    cout << b;
    a = b;
    cout << a;
    student c;
    cin >> c;
    c.increase_year(3);
    cout << c;
    f1(c);
    a = f2();
    cout << a;
}
