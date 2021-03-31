#include <iostream>
#include "List.h"
#include "Pair.h"

using namespace std;

int main() {
    List<int> a(5, 0);
    cin >> a;
    cout << a << endl;
    List<int> b(10, 1);
    cout << b << endl;
    b = a;
    cout << b << endl;
    cout << a[2] << endl;
    cout << "size = " << a() << endl;
    b = a + 10;
    cout << b;
    Pair c;
    cin >> c;
    List<Pair> A(5, c);
    cin >> A;
    cout << A << endl;
    List<Pair> B(10, c);
    cout << B << endl;
    B = A;
    cout << B << endl;
    cout << A[2] << endl;
    cout << "Size = " << A() << endl;
    B = A + c;
    cout << B << endl;
    return 0;
}
