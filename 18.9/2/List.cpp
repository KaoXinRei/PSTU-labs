#include "List.h"

#include "Error.h"

List::List(int s, int k) {
    if (s > MAX_SIZE) throw MaxSizeError();
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = k;
    }
}

List::List(const List &l) {
    size = l.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = l.data[i];
    }
}

List::~List() {
    delete[] data;
}

int &List::operator[](int index) {
    if (index < 0) throw IndexError1();
    if (index > size) throw IndexError2();
    return data[index];
}

List List::operator+(const int k) {
    List tmp(size);
    for (int i = 0; i < size; i++) {
        tmp.data[i] = data[i] + k;
    }
    return tmp;
}

int List::operator()() const {
    return size;
}

ostream &operator<<(ostream &out, const List &l) {
    for (int i = 0; i < l.size; i++) {
        out << l.data[i] << ' ';
    }
    out << endl;
    return out;
}

istream &operator>>(istream &in, List &l) {
    for (int i = 0; i < l.size; i++) {
        in >> l.data[i];
    }
    return in;
}

List &List::operator=(const List &l) {
    if (this == &l) {
        return *this;
    }
    size = l.size;
    delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = l.data[i];
    }
    return *this;
}

void List::operator++() {
    if (size == MAX_SIZE) throw MaxSizeError();
    int *tmp = data;
    data = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        data[i] = tmp[i];
    }
    delete[] tmp;
    int n;
    cout << "What number to add to the list? ";
    cin >> n;
    data[size] = n;
    ++size;
}

List::List() {
    size = 0;
    data = {};
}

