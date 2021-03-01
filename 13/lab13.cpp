#include <iostream>
#include <algorithm>

using namespace std;

bool valid(int x, int y, bool** board)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[x][i])
		{
			return false;
		}
		if (board[i][y])
		{
			return false;
		}
	}
	int delta = x - y;
	for (int i = max(0,delta); i < min(9, 9+delta); i++)
	{
		if (board[i][i-delta])
		{
			return false;
		}
	}
	delta = x - 8 + y;
	for (int i = max(0,delta); i < min(9, 9+delta); i++)
	{
		if (board[i][min(x+y,8)-i])
		{
			return false;
		}
	}
	return true;
}

int place_queens(bool** board, int n)
{
	if (n==0)
	{
		return 0;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (valid(i, j, board))
			{
				board[i][j] = true;
				n -= 1;
				n = place_queens(board, n);
				if (n == 0)
				{
					return 0;
				}
				board[i][j] = false;
				n += 1;
			}
		}
	}
	return n;
}

int main()
{
	bool** board = new bool*[9];
	for (int i = 0; i < 9; i++)
	{
		board[i] = new bool[9];
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = false;
		}
	}
	place_queens(board, 8);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j])
			{
				cout << "* ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}
