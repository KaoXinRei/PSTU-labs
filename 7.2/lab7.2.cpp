#include <iostream>
using namespace std;

int* oct_gen(int n, ...)
{
    int* ans = new int[n];
    int* ptr = &n;
    for (int i = 0; i < n; i++)
    {
        int dec = ptr[i+1];
        bool sign = (dec > 0);
        dec = abs(dec);
        ans[i] = 0;
        int pos = 0;
        while (dec > 0)
        {
            ans[i] += (dec % 8) * pow(10,(pos++));
            dec /= 8;
        }
        if (!sign)
        {
            ans[i] *= -1;
        }
    }
    return ans;
}

int main()
{
    cout << "Enter 3 numbers to convert to octal: ";
    int args[8];
    for (int i = 0; i < 3; i++)
    {
        cin >> args[i];
    }
    cout << "answer: ";
    int* ans = oct_gen(3, args[0], args[1], args[2]);
    cout << "Answer: ";
    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout << "Enter 5 numbers to convert to octal: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> args[i];
    }
    ans = oct_gen(8, args[0], args[1], args[2], args[3], args[4]);
    cout << "Answer: ";
    for (int i = 0; i < 5; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout << "Enter 8 numbers to convert to octal: ";
    for (int i = 0; i < 8; i++)
    {
        cin >> args[i];
    }
    ans = oct_gen(8, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
    cout << "Answer: ";
    for (int i = 0; i < 8; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
