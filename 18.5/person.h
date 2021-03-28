#pragma once

#include "Object.h"
#include <iostream>

using namespace std;

class person : public Object {
protected:
    string name;
    int age;
public:
    person(void);

    virtual ~person(void);

    void show() override;

    person(string, int);

    person(const person &);

    string get_name() { return name; }

    int get_age() { return age; }

    void set_name(string name) { this->name = name; }

    void set_age(int age) { this->age = age; }

    person &operator=(const person &);

    friend istream &operator>>(istream &in, person &p);

    friend ostream &operator<<(ostream &out, const person &p);
};

