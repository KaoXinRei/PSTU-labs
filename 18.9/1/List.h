#pragma once

#include <iostream>

using namespace std;
const int MAX_SIZE = 30;

class List {
private:
    int size;
    int *data;
public:
    explicit List(int s, int k = 0);

    List();

    List(const List &l);

    ~List();

    List &operator=(const List &l);

    int &operator[](int index);

    List operator+(int k);

    void operator++();

    int operator()() const;

    friend ostream &operator<<(ostream &out, const List &l);

    friend istream &operator>>(istream &in, List &l);
};

