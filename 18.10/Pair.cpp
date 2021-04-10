#include <iostream>
#include "Pair.h"

using namespace std;

Pair &Pair::operator=(const Pair &p) {
    if (&p == this) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

bool Pair::operator<(const Pair &p) {
    if (first != p.first) {
        return first < p.first;
    } else {
        return second < p.second;
    }
}

bool Pair::operator>(const Pair &p) {
    if (first != p.first) {
        return first > p.first;
    } else {
        return second > p.second;
    }
}

Pair Pair::operator++(int) {
    second++;
    return *this;
}

Pair Pair::operator++() {
    first++;
    return *this;
}

istream &operator>>(istream &in, Pair &p) {
    cout << "First? ";
    cin >> p.first;
    cout << "Second? ";
    cin >> p.second;
    return in;
}

ostream &operator<<(ostream &out, const Pair &p) {
    return (out << p.first << ":" << p.second << endl);
}

Pair Pair::operator+(Pair p) {
    Pair tmp(first + p.first, second + p.second);
    return tmp;
}

fstream &operator>>(fstream &fin, Pair &p) {
    fin >> p.first;
    fin >> p.second;
    return fin;
}

fstream &operator<<(fstream &fout, const Pair &p) {
    fout << p.first << '\n' << p.second << '\n';
    return fout;
}

bool Pair::operator==(const Pair& p) {
    if(first == p.first){
        if (second == p.second){
            return true;
        }
    }
    return false;
}
