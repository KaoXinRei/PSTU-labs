#include <iostream>
#include "Pair.h"
#include <queue>
#include <list>

using namespace std;
typedef priority_queue<Pair> pq;
typedef list<Pair> lst;

struct mean {
    void operator()(Pair p) {
        ++n;
        s_f += p.get_first();
        s_s += p.get_second();
    }

    Pair get_result() { return Pair(s_f / n, s_s / n); }

private:
    int n{0};
    int s_f{0};
    double s_s{0};
};


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

int main() {
    int n;
    cout << "N? ";
    cin >> n;
    pq q = make_pq(n);
    print_pq(q);
    lst l = copy_pq_to_lst(q);
    mean m = for_each(l.begin(),l.end(), mean());
    q.push(m.get_result());
    print_pq(q);
    Pair f, s;
    cin >> f;
    cin >> s;
    l = copy_pq_to_lst(q);
    l.remove_if([f, s](Pair p) { return ((f < p && p < s)); });
    q = copy_lst_to_pq(l);
    print_pq(q);
    m = for_each(l.begin(), l.end(), mean());
    Pair res = m.get_result();
    for_each(l.begin(), l.end(), [res](Pair& p) { p = p - res; });
    q = copy_lst_to_pq(l);
    print_pq(q);
    return 0;
}