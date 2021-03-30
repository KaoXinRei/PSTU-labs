#pragma once

#include <iostream>

using namespace std;

class Iterator {
private:
    int *elem;

    friend class List;

public:
    Iterator() { elem = nullptr; }

    Iterator(const Iterator &itr) { elem = itr.elem; }

    bool operator==(const Iterator &itr) { return elem == itr.elem; }

    bool operator!=(const Iterator &itr) { return elem != itr.elem; }

    void operator++() { ++elem; }

    void operator--() { --elem; }

    int &operator*() const { return *elem; }
};

class List {
private:
    int size;
    int *data;
    Iterator beg;
    Iterator end;
public:
    explicit List(int s, int k = 0);

    List(const List &l);

    ~List();

    List &operator=(const List &l);

    int &operator[](int index);

    List operator+(int k);

    int operator()() const;

    friend ostream &operator<<(ostream &out, const List &l);

    friend istream &operator>>(istream &in, List &l);

    Iterator first() { return beg; }

    Iterator last() { return end; }
};

