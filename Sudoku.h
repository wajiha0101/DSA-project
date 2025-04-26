#pragma once
#include<iostream>
#include <iomanip>
#include <fstream>


using namespace std;

const int n = 9;
int grid[n][n]; 

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

bool solvesudoku()
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
                        if (solvesudoku())
                            return true;

                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void inputValue()
{
    cout << "Enter a number to solve sukodu:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter 9 numbers for row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            while (grid[i][j] < 0 || grid[i][j] > 9)
            {
                cout << "Invalid input. Enter a number between 0 and 9: ";
                cin >> grid[i][j];
            }
        }
    }
}

