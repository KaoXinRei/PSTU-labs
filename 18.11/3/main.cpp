#include <iostream>
#include "Pair.h"
#include "List.h"
#include <cstdlib>
#include <iterator>
#include <random>

using namespace std;
typedef List<Pair> lst;

int main() {
    try {
        lst l;
        int n;
        cout << "N? ";
        cin >> n;
        l.make(n);
        l.print();
        cout << "Pos?";
        cin >> n;
        l.add_mean(n);
        l.print();
        Pair f, s;
        cin >> f;
        cin >> s;
        l.del(f, s);
        l.print();
        l.decrease_mean();
        l.print();
    }
    catch (int) {
        cout << "error!";
    }
}