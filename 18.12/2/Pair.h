#pragma once

using namespace std;

class Pair {
    int first;
    double second;
public:
    Pair() {
        first = 0;
        second = 0.0;
    }

    Pair(int f, double s) {
        first = f;
        second = s;
    }

    Pair(const Pair &p) {
        first = p.first;
        second = p.second;
    }

    ~Pair() {}

    int get_first() { return first; }

    double get_second() { return second; }

    void set_first(int f) { first = f; }

    void set_second(double s) { second = s; }

    Pair &operator=(const Pair &);

    bool operator<(const Pair &) const;

    bool operator>(const Pair &) const;

    Pair operator++(int);

    Pair operator++();

    friend istream &operator>>(istream &in, Pair &p);

    friend ostream &operator<<(ostream &, const Pair &p);
};
