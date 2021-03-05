#include <iostream>
#include <algorithm>

using namespace std;
int c = 0;
bool valid(int x, int y, bool** board)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j])
            {
                if (y == j || x + y == i + j || x - y == i - j)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int place_queens(bool** board, int n, int x)
{
    if (n==0)
    {
        return 0;
    }
    for (int i = x; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (valid(i, j, board))
            {
                board[i][j] = true;
                n -= 1;
                if (n==0)
                {
                    c++;
                }
                n = place_queens(board, n, i + 1);
                board[i][j] = false;
                n += 1;
            }
        }
    }
    return n;
}

int main()
{
    bool** board = new bool*[8];
    for (int i = 0; i < 8; i++)
    {
        board[i] = new bool[8];
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = false;
        }
    }
    place_queens(board, 8, 0);
    cout << c << endl;
}