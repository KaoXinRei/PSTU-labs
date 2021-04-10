#include <iostream>
#include "List.h"

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
    catch (int e) {
        cout << "ERROR " << e << endl;
    }
    return 0;
}
