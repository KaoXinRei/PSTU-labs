#include <iostream>
#include "Pair.h"
#include <list>
#include <cstdlib>
#include <iterator>
#include <random>

using namespace std;
typedef list<Pair> lst;

lst make_list(int n) {
    lst l;
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(-100, 100);
    for (int i = 0; i < n; ++i) {
        Pair p;
        p.set_first(distr(eng));
        p.set_second(distr(eng));
        l.push_back(p);
    }
    return l;
}

void print_list(lst l) {
    for (auto i: l) {
        cout << i << ' ';
    }
    cout << endl;
}

lst add_mean(lst l, int k) {
    int mf = 0;
    double ms = 0;
    for (auto i: l) {
        mf += i.get_first();
        ms += i.get_second();
    }
    auto li = l.begin();
    advance(li, k);
    mf /= int(l.size());
    ms /= double(l.size());
    l.insert(li, Pair(mf, ms));
    return l;
}

lst del_list(lst l, Pair first, Pair second) {
    lst tmp;
    for (auto i:l) {
        if (!(first < i && i < second)) {
            tmp.push_back(i);
        }
    }
    return tmp;
}

lst decrease_mean(lst l) {
    int mf = 0;
    double ms = 0;
    for (auto i: l) {
        mf += i.get_first();
        ms += i.get_second();
    }
    mf /= int(l.size());
    ms /= double(l.size());
    lst tmp;
    for (auto i:l) {
        tmp.push_back(Pair(i.get_first()-mf,i.get_second()-ms));
    }
    return tmp;
}

int main() {
    try {
        lst l;
        auto li = l.begin();
        int n;
        cout << "N? ";
        cin >> n;
        l = make_list(n);
        print_list(l);
        cout << "Pos?";
        cin >> n;
        l = add_mean(l, n);
        print_list(l);
        Pair f, s;
        cin >> f;
        cin >> s;
        l = del_list(l, f, s);
        print_list(l);
        l = decrease_mean(l);
        print_list(l);
    }
    catch (int) {
        cout << "error!";
    }
}