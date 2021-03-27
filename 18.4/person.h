#pragma once
#include <string>
#include <iostream>

using namespace std;

class person
{
protected:
	string name;
	int age;
public:
	person(void);
public:
	virtual ~person(void);
	person(string, int);
	person(const person&);
	string get_name() { return name; }
	int get_age() { return age; }
	void set_name(string n) { name = n; }
	void set_age(int a) { age = a; }
	person& operator=(const person&);
	friend istream& operator>>(istream& in, person& p);
	friend ostream& operator<<(ostream& out,const person& p);
};

