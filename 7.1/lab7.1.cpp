#include <iostream>
#include <utility> 
using namespace std;

float divide(float a, float b)
{
    return a / b;
}

pair <int, int> divide(pair <int, int> a, pair <int, int> b)
{
    pair <int, int> res;
    res.first = a.first * b.second;
    res.second = a.second * b.first;
    int nod, num1 = res.first, num2 = res.second;
    while (num1 != 0 && num2 != 0)
    {
        if (num1 > num2)
        {
            num1 = num1 % num2;
        }
        else
        {
            num2 = num2 % num1;
        }
    }
    nod = num1 + num2;
    res.first /= nod;
    res.second /= nod;
    return res;
}

int main()
{
    float dec1, dec2;
    cout << "Insert two decimal numbers to divide:\n";
    cin >> dec1 >> dec2;
    cout << "Result: " << divide(dec1, dec2) << endl;
    pair <int, int> rat1, rat2;
    cout << "\nInsert two rational numbers expressed as the fraction a/b(a and b should be separated by <space>): \n";
    cin >> rat1.first >> rat1.second >> rat2.first >> rat2.second;
    pair <int, int> res = divide(rat1, rat2);
    cout << "Result: " << res.first << '/' << res.second;
}

