#include "Object.h"
#include "person.h"
#include <iostream>
#include "student.h"
#include "Vector.h"
#include <string>

using namespace std;

int main() {
    Vector v(5);
    person a;
    cin >> a;
    cout << a;
    Object *ptr = &a;
    ptr->show();
    v.add(ptr);
    student b;
    cin >> b;
    cout << b;
    ptr = &b;
    ptr->show();
    v.add(ptr);
    cout << v;
    return 0;
}
