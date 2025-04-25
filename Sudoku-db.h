#pragma once
#include <string>
#include <vector>
#include "sqlite3.h"

class SudokuDB {
private:
    sqlite3* db;
    bool executeQuery(const std::string& query);
public:
    SudokuDB(const std::string& dbName = "sudoku.db");
    ~SudokuDB();

    bool savePuzzle(const std::string& name, const std::string& data);
    std::string loadPuzzle(const std::string& name);
    std::vector<std::string> getAllPuzzleNames();

    std::string boardToString(int board[9][9]);
    void stringToBoard(const std::string& str, int board[9][9]);

};

