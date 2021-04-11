#include <iostream>
#include <list>
#include <cstdlib>
#include <iterator>

using namespace std;
typedef list<int> lst;

lst make_list(int n) {
    lst l;
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        int a = rand() % 100 - 50;
        l.push_back(a);
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
    int m = 0;
    for (auto i: l) {
        m += i;
    }
    auto li = l.begin();
    advance(li, k);
    m = m / int(l.size());
    l.insert(li, m);
    return l;
}

lst del_list(lst l, int first, int second) {
    lst tmp;
    for (auto i:l) {
        if (!(first < i && i < second)) {
            tmp.push_back(i);
        }
    }
    return tmp;
}

lst decrease_mean(lst l){
    int m = 0;
    for (auto i: l) {
        m += i;
    }
    m = m / int(l.size());
    lst tmp;
    for (auto i:l){
        tmp.push_back(i-m);
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
        int f, s;
        cout << "First? ";
        cin >> f;
        cout << "Second? ";
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
