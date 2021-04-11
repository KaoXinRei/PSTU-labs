#include <iostream>
#include <map>
#include "Pair.h"

using namespace std;
typedef map<int, Pair> tmap;
typedef tmap::iterator it;

tmap make_map(int n) {
    tmap m;
    Pair p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        m.insert(make_pair(i, p));
    }
    return m;
}

void print_map(tmap m) {
    for (int i = 0; i < m.size(); ++i) {
        cout << i << ':' << m[i] << endl;
    }
}

tmap add_mean(tmap m, int pos) {
    int mf = 0;
    double ms = 0;
    for (int i = 0; i < m.size(); ++i) {
        mf += m[i].get_first();
        ms += m[i].get_second();
    }
    mf /= int(m.size());
    ms /= double(m.size());
    for (int i = m.size() - 1; i >= pos; --i) {
        auto k = m.extract(i);
        k.key() = i + 1;
        m.insert(move(k));
    }
    m.insert(make_pair(pos, Pair(mf, ms)));
    return m;
}

tmap del_map(tmap m, Pair f, Pair s) {
    for (int i = 0; i < m.size(); ++i) {
        if (m[i] > f && m[i] < s) {
            m.extract(i);
            for (int j = i + 1; j < m.size() + 1; ++j) {
                auto k = m.extract(j);
                k.key() = j - 1;
                m.insert(move(k));
            }
            --i;
        }
    }
    return m;
}

tmap decrease_mean(tmap m) {
    int mf = 0;
    double ms = 0;
    for (int i = 0; i < m.size(); ++i) {
        mf += m[i].get_first();
        ms += m[i].get_second();
    }
    mf /= int(m.size());
    ms /= double(m.size());
    for (int i = 0; i < m.size(); ++i) {
        m[i].set_first(m[i].get_first() - mf);
        m[i].set_second(m[i].get_second() - ms);
    }
    return m;
}

int main() {
    int n;
    cout << "N?";
    cin >> n;
    tmap m = make_map(n);
    print_map(m);
    cout << "Pos?";
    cin >> n;
    m = add_mean(m, n);
    print_map(m);
    Pair f, s;
    cin >> f;
    cin >> s;
    m = del_map(m, f, s);
    print_map(m);
    m = decrease_mean(m);
    print_map(m);
    return 0;
}
