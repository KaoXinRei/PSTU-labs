#include <iostream>
#include "Pair.h"
#include <queue>
#include <list>

using namespace std;
typedef priority_queue<Pair> pq;
typedef list<Pair> lst;

pq make_pq(int n) {
    pq q;
    Pair p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        q.push(p);
    }
    return q;
}

lst copy_pq_to_lst(pq q) {
    lst l;
    while (!q.empty()) {
        l.push_back(q.top());
        q.pop();
    }
    return l;
}

pq copy_lst_to_pq(lst l) {
    pq q;
    while (!l.empty()) {
        q.push(l.back());
        l.pop_back();
    }
    return q;
}

void print_pq(pq q) {
    while (!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << endl;
}

pq add_mean(pq q) {
    lst l = copy_pq_to_lst(q);
    int mf = 0;
    double ms = 0;
    for (auto i:l) {
        mf += i.get_first();
        ms += i.get_second();
    }
    mf /= int(l.size());
    ms /= double(l.size());
    q.push(Pair(mf, ms));
    return q;
}

pq del_pq(pq q, Pair first, Pair second) {
    lst l = copy_pq_to_lst(q);
    pq tmp;
    for (auto i:l) {
        if (!(first < i && i < second)) {
            tmp.push(i);
        }
    }
    return tmp;
}

pq decrease_mean(pq q) {
    lst l = copy_pq_to_lst(q);
    int mf = 0;
    double ms = 0;
    for (auto i:l) {
        mf += i.get_first();
        ms += i.get_second();
    }
    mf /= int(l.size());
    ms /= double(l.size());
    pq tmp;
    for (auto i:l) {
        tmp.push(Pair(i.get_first() - mf, i.get_second() - ms));
    }
    return tmp;
}

int main() {
    try {
        int n;
        cout << "N? ";
        cin >> n;
        pq q = make_pq(n);
        print_pq(q);
        q = add_mean(q);
        print_pq(q);
        Pair f, s;
        cin >> f;
        cin >> s;
        q = del_pq(q, f, s);
        print_pq(q);
        q = decrease_mean(q);
        print_pq(q);
    }
    catch (int) {
        cout << "error!";
    }
}
