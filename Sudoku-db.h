#pragma once
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;

class SudokuDB {
private:
    sqlite3* db;
    bool executeQuery(const string& query);
public:
    SudokuDB(const string& dbName = "sudoku.db");
    ~SudokuDB();

    bool savePuzzle(const string& name, const string& data);
    string loadPuzzle(const string& name);
    vector<string> getAllPuzzleNames();

    string boardToString(int board[9][9]);
    void stringToBoard(const string& str, int board[9][9]);

};

