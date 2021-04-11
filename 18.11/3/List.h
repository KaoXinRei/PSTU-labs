#pragma once

#include <iostream>
#include <random>

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

    void insert(int, T);

    void make(int n);

    void print();

    void add_mean(int k);

    void del(T first, T second);

    void decrease_mean();

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
    if (size == ps) {
        data[size] = k;
        size++;
    }
    delete[] tmp;
}

template<class T>
void List<T>::make(int n) {
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(-100, 100);
    for (int i = 0; i < n; ++i) {
        Pair p;
        p.set_first(distr(eng));
        p.set_second(distr(eng));
        push_back(p);
    }
}

template<class T>
void List<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

template<class T>
void List<T>::add_mean(int k) {
    int mf = 0;
    double ms = 0;
    for (int i = 0; i < size; ++i) {
        mf += data[i].get_first();
        ms += data[i].get_second();
    }
    mf /= size;
    ms /= size;
    insert(k, Pair(mf, ms));
}

template<class T>
void List<T>::del(T first, T second) {
    List<T> tmp;
    for (int i = 0; i < size; ++i) {
        if (!(first < data[i] && data[i] < second)) {
            tmp.push_back(data[i]);
        }
    }
    size = tmp.size;
    T *to_del = data;
    data = tmp.data;
    delete[] to_del;
    tmp.data = nullptr;
}

template<class T>
void List<T>::decrease_mean() {
    int mf = 0;
    double ms = 0;
    for (int i = 0; i < size; ++i) {
        mf += data[i].get_first();
        ms += data[i].get_second();
    }
    mf /= size;
    ms /= size;
    List<T> tmp;
    for (int i = 0; i < size; ++i) {
        tmp.push_back(Pair(data[i].get_first() - mf, data[i].get_second() - ms));
    }
    T *to_del = data;
    data = tmp.data;
    delete[] to_del;
    tmp.data = nullptr;
}

