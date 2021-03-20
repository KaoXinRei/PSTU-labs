#include "phone_call.h"
#include <iostream>

using namespace std;

phone_call make_phone_call(int f, double s) {
	phone_call p;
	p.init(f, s);
	return p;
}

int main() {
	phone_call A;
	phone_call B;
	A.init(5, 2.3);
	B.read();
	A.show();
	B.show();
	cout << "A.coast(" << A.first << ", " << A.second << ") = " << A.coast() << endl;
	cout << "B.coast(" << B.first << ", " << B.second << ") = " << B.coast() << endl;
	phone_call* X = new phone_call;
	X->init(2, 0.5);
	X->show();
	X->coast();
	cout << "X.coast(" << X->first << ", " << X->second << ") = " << X->coast() << endl;
	phone_call mas[3];
	for (int i = 0; i < 3; i++) {
		mas[i].read();
	}
	for (int i = 0; i < 3; i++) {
		mas[i].show();
	}
	for (int i = 0; i < 3; i++) {
		mas[i].coast();
		cout << "mas["<<i<<"].coast(" << mas[i].first << ", " << mas[i].second << ") = " << mas[i].coast() << endl;
	}
	phone_call* p_mas = new phone_call[3];
	for (int i = 0; i < 3; i++) {
		p_mas[i].read();
	}
	for (int i = 0; i < 3; i++) {
		p_mas[i].show();
	}
	for (int i = 0; i < 3; i++) {
		mas[i].coast();
		cout << "p_mas[" << i << "].coast(" << p_mas[i].first << ", " << p_mas[i].second << ") = " << p_mas[i].coast() << endl;
	}
	int y; double z;
	cout << "first? "; cin >> y;
	cout << "second? "; cin >> z;
	phone_call f = make_phone_call(y, z);
	f.show();
}