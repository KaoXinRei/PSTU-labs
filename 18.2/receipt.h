#pragma once
#include <string>
using namespace std;

class receipt {
	int number;
	string date;
	double sum;
public:
	receipt();
	receipt(int, string, double);
	receipt(const receipt&);
	~receipt();
	int get_number();
	void set_number(int);
	string get_date();
	void set_date(string);
	double get_sum();
	void set_sum(double);
	void show();
};