#include <iostream>
#include <list>
#include <algorithm>
#include "Pair.h"
#include <random>

using namespace std;
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

int main() {
    lst l;
    int n;
    cout << "N? ";
    cin >> n;
    l = make_list(n);
    print_list(l);
    cout << "Pos?";
    cin >> n;
    mean m = for_each(l.begin(), l.end(), mean());
    auto li = l.begin();
    advance(li, n);
    l.insert(li, m.get_result());
    print_list(l);
    Pair f, s;
    cin >> f;
    cin >> s;
    l.remove_if([f, s](Pair p) { return ((f < p && p < s)); });
    print_list(l);
    m = for_each(l.begin(), l.end(), mean());
    Pair res = m.get_result();
    for_each(l.begin(), l.end(), [res](Pair& p) { p = p - res; });
    print_list(l);
    return 0;
}
