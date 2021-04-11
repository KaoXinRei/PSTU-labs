#include <iostream>
#include <map>

using namespace std;
typedef map<int, int> tmap;
typedef tmap::iterator it;

tmap make_map(int n) {
    tmap m;
    int a;
    for (int i = 0; i < n; ++i) {
        cout << "?";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_map(tmap m) {
    for (int i = 0; i < m.size(); ++i) {
        cout << i << ':' << m[i] << endl;
    }
}

tmap add_mean(tmap m, int pos) {
    int mean = 0;
    for (auto i: m) {
        mean += i.second;
    }
    mean /= int(m.size());
    for (int i = m.size() - 1; i >= pos; --i) {
        auto k = m.extract(i);
        k.key() = i + 1;
        m.insert(move(k));
    }
    m.insert(make_pair(pos, mean));
    return m;
}

tmap del_map(tmap m, int f, int s) {
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
    int mean = 0;
    for (auto i: m) {
        mean += i.second;
    }
    mean /= int(m.size());
    for (int i = 0; i < m.size(); ++i) {
        m[i]-= mean;
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
    int f, s;
    cout << "First? ";
    cin >> f;
    cout << "Second? ";
    cin >> s;
    m = del_map(m, f, s);
    print_map(m);
    m = decrease_mean(m);
    print_map(m);
    return 0;
}
