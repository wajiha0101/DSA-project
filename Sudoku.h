#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

const int n = 9;

void printboard(int grid[9][9]);
bool isSafe(int grid[9][9], int row, int col, int num);
bool isBoardEmpty(int grid[9][9]);
bool isInitialBoardValid(int grid[9][9]);
bool solvesudoku(int grid[9][9]);
void inputValue(int grid[9][9]);
void userSolve(int grid[9][9]);