#include "receipt.h"
#include <iostream>
#include <string>

using namespace std;

receipt::receipt() {
	number = 0;
	date = "";
	sum = 0.0;
	cout << "Empty constructor for " << this << endl;
}

receipt::receipt(int n, string d, double s) {
	number = n;
	date = d;
	sum = s;
	cout << "Constructor with parameters for " << this << endl;
}

receipt::receipt(const receipt &r) {
	number = r.number;
	date = r.date;
	sum = r.sum;
	cout << "Copy constructor for " << this << endl;
}

receipt::~receipt() {
	cout << "Destructor for " << this << endl;
}

int receipt::get_number() {
	return number;
}

string receipt::get_date(){
	return date;
}

double receipt::get_sum() {
	return sum;
}

void receipt::set_number(int n) {
	number = n;
}

void receipt::set_date(string d) {
	date = d;
}

void receipt::set_sum(double s) {
	sum = s;
}

void receipt::show() {
	cout << "Number: " << number << endl;
	cout << "Date: " << date << endl;
	cout << "Sum: " << sum << endl;
}