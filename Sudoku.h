#pragma once
#include <iostream>
#include <iomanip>


using namespace std;

const int n = 9;
extern int grid[n][n]; 

void printboard();
bool isSafe(int row, int col, int num);
bool solvesudoku();
void inputValue();
