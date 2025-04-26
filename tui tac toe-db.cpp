#include "tic tac toe-db.h"
#include <iostream>
using namespace std;

TicTacToeDB::TicTacToeDB(const string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
    }
    else {
        string createTable = "CREATE TABLE IF NOT EXISTS games ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "board_state TEXT NOT NULL, "
            "result TEXT NOT NULL);";
        executeQuery(createTable);
    }
}

TicTacToeDB::~TicTacToeDB() {
    sqlite3_close(db);
}

bool TicTacToeDB::executeQuery(const string& query) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool TicTacToeDB::saveGame(const string& name, const string& boardState, const string& result) {
    string query = "REPLACE INTO games (name, board_state, result) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, boardState.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, result.c_str(), -1, SQLITE_STATIC);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return success;
}

string TicTacToeDB::loadGame(const string& name) {
    string query = "SELECT board_state FROM games WHERE name = ?;";
    sqlite3_stmt* stmt;
    string boardState = "";

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return boardState;

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        boardState = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return boardState;
}

vector<string> TicTacToeDB::getAllGameNames() {
    string query = "SELECT name FROM games;";
    sqlite3_stmt* stmt;
    vector<string> names;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return names;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        names.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    }

    sqlite3_finalize(stmt);
    return names;
}
