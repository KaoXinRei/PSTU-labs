#include <iostream>
#include "Pair.h"

using namespace std;

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

bool Pair::operator<(const Pair& p) {
	return this->first < p.first;
}

bool Pair::operator>(const Pair& p) {
	return this->first > p.first;
}

Pair Pair::operator++(int) {
	second++;
	return *this;
}

Pair Pair::operator++() {
	first++;
	return *this;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "First? "; cin >> p.first;
	cout << "Second? "; cin >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << p.first << ":" << p.second);
}
