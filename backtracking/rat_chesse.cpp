#include <iostream>
using namespace std;

#define size 4

void printSol(bool sol[size][size]);

bool isSafe(bool maze[size][size], int x, int y)
{
    return x < size && y < size && maze[x][y];
}

bool solveMaze_R(bool maze[size][size], bool sol[size][size], int x = 0, int y = 0)
{
    if (x == size - 1 && y == size - 1 && maze[x][y])
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y) == true)
    {
        sol[x][y] = 1;

        if (solveMaze_R(maze, sol, x + 1, y) == true)
            return true;

        if (solveMaze_R(maze, sol, x, y + 1) == true)
            return true;

        maze[x][y] = 0;
    }

    return false;
}

bool solveMaze(bool maze[size][size])
{
    bool sol[size][size] = {{0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};

    if (solveMaze_R(maze, sol) == false)
        return false;

    printSol(sol);
    return true;
}

void printSol(bool sol[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 && j == 0)
                cout << "M";
            else if (i == size - 1 && j == size - 1)
                cout << "C";
            else if (sol[i][j])
                cout << ". ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main()
{
    bool maze[size][size] = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 0, 0},
                             {1, 1, 1, 1}};

    solveMaze(maze);
}