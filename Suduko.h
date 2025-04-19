#pragma once
#include<iostream>
#include <iomanip>

using namespace std;

const int n = 9;
int grid[n][n] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printboard()
{
    for (int row = 0; row < n; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            cout << "------+-------+------\n";
        }

        for (int col = 0; col < n; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                cout << "| ";
            }

            if (grid[row][col] == 0)
                cout << setw(2) << ".";
            else
                cout << setw(2) << grid[row][col];
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, int num)
{
    for (int c = 0; c < n; c++)
    {
        if (grid[row][c] == num) return false;
    }

    for (int r = 0; r < n; r++)
    {
        if (grid[r][col] == num) return false;
    }

    int inirow = row-row % 3;
    int inicol = col - col % 3;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[inirow + i][inicol + j] == num) return false;
        }
    }
    return true;
}

bool solvesuduko()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(i, j, num))
                    {
                        grid[i][j] = num;
                    }
                }
            }
        }
    }
}