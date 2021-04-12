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

    Pair operator-(Pair);

    Pair operator++(int);

    Pair operator++();

    friend istream &operator>>(istream &in, Pair &p);

    friend ostream &operator<<(ostream &, const Pair &p);
};
Pair &Pair::operator=(const Pair &p) {
    if (&p == this) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

bool Pair::operator<(const Pair &p) const {
    if (first != p.first) {
        return first < p.first;
    } else {
        return second < p.second;
    }
}

bool Pair::operator>(const Pair &p) const {
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
    return (out << p.first << ":" << p.second);
}

Pair Pair::operator-(Pair p) {
    first -= p.first;
    second -= p.second;
    return *this;
}
