#pragma once
#include "person.h"

using namespace std;

class student : public person {
public:
	student(void);
protected:
	int year;
public:
	~student(void);
	student(string, int, int);
	student(const student&);
	int get_year() { return year; }
	void set_year(int y) { year = y; }
	void increase_year(int y) { year += y; }
	student& operator=(const student&);
	friend istream& operator>>(istream& in, student& s);
	friend ostream& operator<<(ostream& out, const student& s);
};