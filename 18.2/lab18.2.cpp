#include <iostream>
#include <string>
#include "receipt.h"
using namespace std;

receipt make_receipt() {
    int n;
    string d;
    double s;
    cout << "Enter number: ";
    cin >> n;
    cout << "Enter date: ";
    cin >> d;
    cout << "Enter sum: ";
    cin >> s;
    return receipt(n, d, s);
}

void print_receipt(receipt r){
    r.show();
}

int main()
{
    receipt r1;
    r1.show();
    receipt r2(5, "4.05.2018", 123.5);
    r2.show();
    receipt r3 = r2;
    r3.set_number(3);
    r3.set_date("12.09.2019");
    r3.set_sum(540.15);
    print_receipt(r3);
    r1 = make_receipt();
    r1.show();
}
