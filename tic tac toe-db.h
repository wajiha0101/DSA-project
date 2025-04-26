#pragma once
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;

class TicTacToeDB {
private:
    sqlite3* db;
    bool executeQuery(const string& query);

public:
    TicTacToeDB(const string& dbName = "tictactoe.db");
    ~TicTacToeDB();

    bool saveGame(const string& name, const string& boardState, const string& result);
    string loadGame(const string& name);
    vector<string> getAllGameNames();
};
