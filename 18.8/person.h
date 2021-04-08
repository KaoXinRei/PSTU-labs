#pragma once

#include "object.h"
#include <iostream>

using namespace std;

class person : public object {
protected:
    string name;
    int age;
public:
    person(void);

    virtual ~person(void);

    void show() override;

    void input() override;

    person(string, int);

    person(const person &);

    string get_name() override { return name; }

    int get_age() { return age; }

    void set_name(string n) { name = n; }

    void set_age(int a) { age = a; }

    person &operator=(const person &);

};

