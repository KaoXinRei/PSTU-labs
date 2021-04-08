#pragma once

#include "object.h"
#include <string>

class tree {
protected:
    object *item;
    tree *left;
    tree *right;
private:
    void removeRight();

    void removeLeft();

    void removeItem();

public:
    explicit tree(object *);

    tree();

public:
    ~tree();

    void add(object *);

    void del(std::string n);

    void show();
};