#pragma once
#include<iostream>
#include <iomanip>


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

    int inirow = row - row % 3;
    int inicol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
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

void userSolve()
{
    int row, col, num;
    while (true) {
        printboard();
        cout << "Enter Row (1-9), Column (1-9), and Number (1-9), or 0 0 0 to solve/check: ";
        cin >> row >> col >> num;

        if (row == 0 && col == 0 && num == 0) {
            break;
        }

        if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && num <= 9) {
            if (grid[row - 1][col - 1] == 0) {
                if (isSafe(row - 1, col - 1, num)) {
                    grid[row - 1][col - 1] = num;
                }
                else {
                    cout << "Invalid move!\n";
                }
            }
            else {
                cout << "Cell already filled.\n";
            }
        }
        else {
            cout << "Invalid input.\n";
        }
    }
}








//#include "Sudoku.h"
//#include "Sudoku-db.h"
//#include <iostream>
//
//using namespace std;
//
//void sudokuMenu() {
//    SudokuDB db("sudoku.db");
//    int choice;
//
//    while (true) {
//        cout << "\n--- Sudoku Menu ---\n";
//        cout << "1. Solve New Sudoku\n";
//        cout << "2. Save Current Sudoku\n";
//        cout << "3. Load Sudoku Puzzle\n";
//        cout << "4. Show Saved Puzzles\n";
//        cout << "5. Exit Sudoku\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == 1) {
//            inputValue();
//            cout << "\nInput Sudoku Board:\n";
//            printboard();
//            if (solvesudoku()) {
//                cout << "\nSolved Sudoku Board:\n";
//                printboard();
//            }
//            else {
//                cout << "No solution exists.\n";
//            }
//        }
//        else if (choice == 2) {
//            string name;
//            cout << "Enter a name for this puzzle: ";
//            cin >> name;
//            string boardData = db.boardToString(grid);
//            if (db.savePuzzle(name, boardData)) {
//                cout << "Puzzle saved successfully.\n";
//            }
//            else {
//                cout << "Failed to save puzzle.\n";
//            }
//        }
//        else if (choice == 3) {
//            string name;
//            cout << "Enter the name of the puzzle to load: ";
//            cin >> name;
//            string data = db.loadPuzzle(name);
//            if (!data.empty()) {
//                db.stringToBoard(data, grid);
//                cout << "Loaded Sudoku Puzzle:\n";
//                printboard();
//            }
//            else {
//                cout << "Puzzle not found.\n";
//            }
//        }
//        else if (choice == 4) {
//            vector<string> names = db.getAllPuzzleNames();
//            cout << "\nSaved Puzzles:\n";
//            for (const auto& n : names) {
//                cout << "- " << n << "\n";
//            }
//        }
//        else if (choice == 5) {
//            cout << "Exiting Sudoku...\n";
//            break;
//        }
//        else {
//            cout << "Invalid choice. Try again.\n";
//        }
//    }
//}
