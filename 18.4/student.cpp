#include "student.h"

using namespace std;

student::student(void) : person() {
	year = 0;
}

student::~student(void) {}

student::student(string n, int a, int y) : person(n, a) {
	year = y;
}

student::student(const student& s) {
	name = s.name;
	age = s.age;
	year = s.year;
}

student& student::operator=(const student& s) {
	if (&s == this) {
		return *this;
	}
	name = s.name;
	age = s.age;
	year = s.year;
	return *this;
}

istream& operator>>(istream& in, student& s) {
	cout << "Name: "; in >> s.name;
	cout << "Age: "; in >> s.age;
	cout << "Year: "; in >> s.year;
	return in;
}

ostream& operator<<(ostream& out, const student& s) {
	out << "Name: " << s.name << endl;
	out << "Age: " << s.age << endl;
	out << "Year: "<< s.year << endl;
	return out;
}