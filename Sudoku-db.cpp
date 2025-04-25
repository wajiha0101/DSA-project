#include "Sudoku-db.h"
#include <iostream>

SudokuDB::SudokuDB(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
    }
    else {
        std::string createTable = "CREATE TABLE IF NOT EXISTS puzzles ("
            "name TEXT PRIMARY KEY, "
            "data TEXT NOT NULL);";
        executeQuery(createTable);
    }
}

SudokuDB::~SudokuDB() {
    sqlite3_close(db);
}

bool SudokuDB::executeQuery(const std::string& query) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool SudokuDB::savePuzzle(const std::string& name, const std::string& data) {
    std::string query = "REPLACE INTO puzzles (name, data) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return false;
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, data.c_str(), -1, SQLITE_STATIC);
    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return success;
}

std::string SudokuDB::loadPuzzle(const std::string& name) {
    std::string query = "SELECT data FROM puzzles WHERE name = ?;";
    sqlite3_stmt* stmt;
    std::string data = "";

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return data;

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }
    sqlite3_finalize(stmt);
    return data;
}

std::vector<std::string> SudokuDB::getAllPuzzleNames() {
    std::string query = "SELECT name FROM puzzles;";
    sqlite3_stmt* stmt;
    std::vector<std::string> names;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return names;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        names.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    }
    sqlite3_finalize(stmt);
    return names;
}


std::string boardToString(int board[9][9]) {
    std::string str = "";
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            str += std::to_string(board[i][j]);
    return str;
}

void stringToBoard(const std::string& str, int board[9][9]) {
    int index = 0;
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = str[index++] - '0';
}
