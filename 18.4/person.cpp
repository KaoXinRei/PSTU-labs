#include "person.h"
#include <iostream>

using namespace std;

person::person(void) {
	name = "";
	age = 0;
}

person::~person(void) {}

person::person(string n, int a) {
	name = n;
	age = a;
}

person::person(const person& p) {
	name = p.name;
	age = p.age;
}

person& person::operator=(const person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

istream& operator>>(istream& in, person& p)
{
	cout << "Name? "; in >> p.name;
	cout << "Age? "; in >> p.age;
	return in;
}

ostream& operator<<(ostream& out, const person& p)
{
	out << "Name: " << p.name << endl;
	out << "Age: " << p.age << endl;
	return out;
}

