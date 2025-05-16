#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

const int n = 9;

// Function to print the Sudoku board
void printboard(int grid[9][9])
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

// Check if a number can be placed in the given position
bool isSafe(int grid[9][9], int row, int col, int num)
{
    for (int c = 0; c < n; c++)
    {
        if (grid[row][c] == num) return false;
    }

    for (int r = 0; r < n; r++)
    {
        if (grid[r][col] == num) return false;
    }

    int inirow = row - row % 3;
    int inicol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[inirow + i][inicol + j] == num) return false;
        }
    }
    return true;
}

// Check if the board is empty
bool isBoardEmpty(int grid[9][9])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] != 0)
                return false;
        }
    }
    return true;
}

// Check if the initial board is valid
bool isInitialBoardValid(int grid[9][9])
{
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            int num = grid[row][col];
            if (num != 0)
            {
                grid[row][col] = 0;  // Temporarily remove the number
                if (!isSafe(grid, row, col, num))
                {
                    grid[row][col] = num;  // Restore
                    return false;  // Conflict detected
                }
                grid[row][col] = num;  // Restore
            }
        }
    }
    return true;
}

// Solve the Sudoku puzzle
bool solvesudoku(int grid[9][9])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(grid, i, j, num))
                    {
                        grid[i][j] = num;
                        if (solvesudoku(grid))
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

// Function to input values (not used in GUI, optional)
void inputValue(int grid[9][9])
{
    cout << "Enter a number to solve Sudoku:" << endl;
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

// Function for user to manually solve (not used in GUI, optional)
void userSolve(int grid[9][9])
{
    int row, col, num;
    while (true)
    {
        printboard(grid);
        cout << "Enter Row (1-9), Column (1-9), and Number (1-9), or 0 0 0 to solve/check: ";
        cin >> row >> col >> num;

        if (row == 0 && col == 0 && num == 0)
        {
            break;
        }

        if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && num <= 9)
        {
            if (grid[row - 1][col - 1] == 0)
            {
                if (isSafe(grid, row - 1, col - 1, num))
                {
                    grid[row - 1][col - 1] = num;
                }
                else
                {
                    cout << "Invalid move!\n";
                }
            }
            else
            {
                cout << "Cell already filled.\n";
            }
        }
        else
        {
            cout << "Invalid input.\n";
        }
    }
}