#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	int a[100];
	int n, m;
	srand(time(0));
	cout << "Size of array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << "Element number to delete: ";
	cin >> m;
	for (int i = m; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << "Element number to insert: ";
	int k, elem;
	cin >> k;
	cout << "Element: ";
	cin >> elem;
	n++; 
	for (int i = k; i < n; i++)
	{
		int tmp = a[i];
		a[i] = elem;
		elem = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	int even;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 1)
		{
			even = -1;
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] % 2 == 0)
				{
					even = j;
				}
			}
			if (even == -1)
			{
				break;
			}
			int tmp = a[i];
			a[i] = a[even];
			a[even] = tmp;
		}
	}
	cout << "Array after putting even numbers at the beginning and odd at the end: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	int mean = 0, nmean = -1, ncompare = 0;
	for (int i = 0; i < n; i++)
	{
		mean += a[i];
	}
	mean /= n;
	for (int i = 0; i < n; i++)
	{
		ncompare++;
		if (a[i] == mean)
		{
			nmean = i;
			break;
		}
	}
	cout << endl;
	if (nmean == -1)
	{
		cout << "No mean element found";
	}
	else
	{
		cout << "Mean is " << mean << endl;
		cout << "Mean element number is " << nmean << endl;
		cout << "It took " << ncompare << " comparisons to find it";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		int j = i - 1, elem = a[i];
		while (j >= 0 && elem < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = elem;
	}
	cout << "Array after sorting: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	ncompare = 0;
	for (int i = 0; i < n; i++)
	{
		ncompare++;
		if (a[i] == mean)
		{
			nmean = i;
			break;
		}
	}
	if (nmean == -1)
	{
		cout << "No mean element found";
	}
	else
	{
		cout << "Mean is " << mean << endl;
		cout << "Mean element number is " << nmean << endl;
		cout << "It took " << ncompare << " comparisons to find it";
	}
}