#include <iostream>
#include "List.h"
#include "Error.h"
using namespace std;

int main() {
    try {
        List x(29, 0);
        List y;
        cout << x;
        cout << "Number? ";
        int i;
        cin >> i;
        cout << x[i] << endl;
        ++x;
        cout << x;
        ++x;
        cout << x;
    }
    catch (Error& e) {
        e.what();
    }
    return 0;
}
