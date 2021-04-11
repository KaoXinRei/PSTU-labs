#pragma once

#include <iostream>

using namespace std;

template<class T>
class List {
private:
    int size;
    T *data{};
public:
    explicit List(int s, T k);

    List();

    List(const List<T> &l);

    ~List();

    List<T> &operator=(const List<T> &l);

    T &operator[](int index);

    List<T> operator+(T k);

    void push_back(T);

    void pop_back();

    T back();

    void insert(int, T);

    int operator()() const;

    friend ostream &operator<<(ostream &out, const List<T> &l);

    friend istream &operator>>(istream &in, List<T> &l);
};

template<class T>
List<T>::List(int s, T k) {
    size = s;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = k;
    }
}

template<class T>
List<T>::List(const List &l) {
    size = l.size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = l.data[i];
    }
}

template<class T>
List<T>::~List() {
    delete[] data;
    data = nullptr;
}

template<class T>
T &List<T>::operator[](int index) {
    if (index < size) {
        return data[index];
    } else {
        cout << "\nError: index out of range";
    }
}

template<class T>
List<T> List<T>::operator+(const T k) {
    List<T> tmp(size, k);
    for (int i = 0; i < size; i++) {
        tmp.data[i] = data[i] + k;
    }
    return tmp;
}

template<class T>
int List<T>::operator()() const {
    return size;
}

template<class T>
ostream &operator<<(ostream &out, const List<T> &l) {
    for (int i = 0; i < l.size; i++) {
        out << l.data[i] << ' ';
    }
    return out;
}

template<class T>
istream &operator>>(istream &in, List<T> &l) {
    for (int i = 0; i < l.size; i++) {
        in >> l.data[i];
    }
    return in;
}

template<class T>
List<T> &List<T>::operator=(const List<T> &l) {
    if (this == &l) {
        return *this;
    }
    size = l.size;
    delete[] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = l.data[i];
    }
    return *this;
}

template<class T>
void List<T>::push_back(T k) {
    T *tmp = data;
    data = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        data[i] = tmp[i];
    }
    delete[] tmp;
    data[size] = k;
    ++size;
}

template<class T>
List<T>::List() {
    size = 0;
    data = new T[0];
}

template<class T>
void List<T>::insert(int pos, T k) {
    T *tmp = data;
    int ps = size;
    data = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        if (i == pos) {
            data[i] = k;
            ++size;
        }
        data[i + size - ps] = tmp[i];
    }
    if (size == ps){
        data[size] = k;
        size++;
    }
    delete[] tmp;
}

template<class T>
T List<T>::back() {
    return data[size-1];
}

template<class T>
void List<T>::pop_back() {
    T *tmp = data;
    --size;
    data = new T[size];
    for (int i = 0; i < size; ++i) {
        data[i] = tmp[i];
    }
    delete[] tmp;
}

