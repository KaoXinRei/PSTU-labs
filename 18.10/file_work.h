#pragma once

#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char *f_name) {
    fstream stream(f_name, ios::out | ios::trunc);
    if (!stream) return -1;
    int n;
    Pair p;
    cout << "How many pairs to make? ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        stream << p << '\n';
    }
    stream.close();
    return n;
}

int print_file(const char *f_name) {
    fstream stream(f_name, ios::in);
    if (!stream) return -1;
    Pair p;
    int i = 0;
    while (stream >> p) {
        cout << p;
        i++;
    }
    stream.close();
    return i;
}

int del_file(const char *f_name, Pair k) {
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)return -1;
    int i = 0;
    Pair p;
    while (stream >> p) {
        if (stream.eof())break;
        ++i;
        if (!(p > k)) temp << p;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}

int increase_file(const char *f_name, const Pair &k, const Pair &a) {
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)return -1;
    Pair p;
    int i = 0;
    while (stream >> p) {
        if (stream.eof())break;
        if (p == k) {
            temp << p + a;
            ++i;
        } else {
            temp << p;
        }
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}

int add_file(const char *f_name, int pos, int size, Pair *items) {
    fstream temp("temp", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream)return -1;
    Pair p;
    int i = -1;
    while (stream >> p) {
        if (i == pos) {
            for (int j = 0; j < size; ++j) {
                temp << items[j];
            }
        }
        if (stream.eof())break;
        temp << p;
        i++;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return i;
}