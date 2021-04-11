#include <iostream>
#include "Pair.h"
#include <queue>
#include "List.h"

using namespace std;
typedef priority_queue<Pair> pq;
typedef List<Pair> lst;

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
    while (!(l()==0)) {
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
    for (int i = 0; i < l(); ++i) {
        mf += l[i].get_first();
        ms += l[i].get_second();
    }
    mf /= int(l());
    ms /= double(l());
    q.push(Pair(mf, ms));
    return q;
}

pq del_pq(pq q, Pair first, Pair second) {
    lst l = copy_pq_to_lst(q);
    pq tmp;
    for (int i = 0; i < l(); ++i) {
        if (!(first < l[i] && l[i] < second)) {
            tmp.push(l[i]);
        }
    }
    return tmp;
}

pq decrease_mean(pq q) {
    lst l = copy_pq_to_lst(q);
    int mf = 0;
    double ms = 0;
    for (int i = 0; i < l(); ++i) {
        mf += l[i].get_first();
        ms += l[i].get_second();
    }
    mf /= int(l());
    ms /= double(l());
    pq tmp;
    for (int i = 0; i < l(); ++i) {
        tmp.push(Pair(l[i].get_first() - mf, l[i].get_second() - ms));
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
