#include <iostream>
using namespace std;

// N > 3 for this problem
// No queen should be able to meet with another in any
// direction - horizontal, vertical or diagonal

#define N 4
#define greentxt "\033[0;32m"
#define nocolo "\033[0m"

bool board[N][N];

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << greentxt << "Q " << nocolo;
            else

                cout << ". ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col)
{
    // check horizontally in row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // check up diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // check down diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens_R(int col = 0)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;
            if (solveNQueens_R(col + 1))
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQueens()
{
    if (!solveNQueens_R())
        return false;

    printBoard();
    return true;
}

int main()
{
    if (N < 4)
    {
        cout << "won't work" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    solveNQueens();
}