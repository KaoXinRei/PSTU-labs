#include <iostream>
#include "Pair.h"

using namespace std;

int main()
{
	Pair a;
	Pair b;
	Pair c;
	cin >> a;
	cin >> b;
	++a;
	cout << a << endl;
	c = a++;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "a > b = " << (a > b) << endl;
	cout << "b < c = " << (b < c);
}