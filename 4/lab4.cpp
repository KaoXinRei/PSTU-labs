#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int a[100];
	int n;
	srand(time(0));
	cout << "Size of array: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
	cout << "Array: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	int i_max = 0, i_min = 0, min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			i_max = i;
		}
		else if (a[i] < min)
		{
			min = a[i];
			i_min = i;
		}
	}
	a[i_max] = min;
	a[i_min] = max;
	cout << "Array after swapping min and max elements: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	float mean = 0;
	for (int i = 0; i < n; i++)
	{
		mean += a[i];
	}
	mean /= n;
	mean *= 1.1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > mean)
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
	cout << "Array after deleting all elements bigger than " << mean << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
}

