#pragma once
#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe();
    void printBoard();
    bool makeMove(int row, int col);
    bool checkWinner();
    bool isBoardFull();
    void playGame();
    void resetBoard();
  string getBoardState();
    void setBoardState(const string& state);
};
