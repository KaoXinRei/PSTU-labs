#include <iostream>
using namespace std;

void f(int **arr, int n, int m, int l)
{
    int max = arr[l][0];
    for (int i = 1; i < m; i++)
    {
        if (arr[l][i] > max)
        {
            max = arr[l][i];
        }
    }
    max %= n;
    int* prew = arr[0];
    for (int i = 1; i <= n; i++)
    {
        int* tmp = arr[(i * max) % n];
        arr[(i * max)%n] = prew;
        prew = tmp;
    }

}
 int main()
{
    int n, m, l;
    cout << "Number of lines in 2d array: ";
    cin >> n;
    cout << "Number of elements in one line: ";
    cin >> m;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }
    cout << "Elements: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "Search in line number: ";
    cin >> l;
    f(a, n, m, l);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

