
#include <iostream>
using namespace std;

int rectangle(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return a > b ? 1 + rectangle(a - b, b) : 1 + rectangle(a, b - a);
    }
}

int main()
{
    int a, b;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << rectangle(a, b);
}
