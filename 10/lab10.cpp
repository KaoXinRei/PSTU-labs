#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int n, k, element;
	cout << "Enter the number of rows in array: ";
	cin >> n;
	cout << "Enter the number of elements un a row: ";
	cin >> k;
	int** arr;
	arr = new int*[n];
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[k];
		for (int j = 0; j < k; j++)
		{
			arr[i][j] = rand() % 20 - 10;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "Rows with what number should be deleted? ";
	cin >> element;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (arr[i][j] == element)
			{
				delete arr[i];
				n--;
				for (int t = i; t < n; t++)
				{
					arr[t] = arr[t + 1];
				}
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	delete[]arr;
}
