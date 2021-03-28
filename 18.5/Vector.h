#pragma once

#include <iostream>
#include "Object.h"
#include <string>

using namespace std;

class Vector {
public:
    Vector(void);

    Vector(int);

public:
    ~Vector(void);

    void add(Object *);

    friend ostream &operator<<(ostream &out, const Vector &v);

private:
    Object **beg;
    int size;
    int cur;
};
