#include "tic tac toe.h"
using namespace std;

TicTacToe::TicTacToe() {
    board = vector<vector<char>>(3, vector<char>(3, ' '));
    currentPlayer = 'X';
}

void TicTacToe::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool TicTacToe::makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool TicTacToe::checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;

    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void TicTacToe::playGame() {
    int row, col;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (makeMove(row, col)) {
            if (checkWinner()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            else if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }
}

void TicTacToe::resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

string TicTacToe::getBoardState() {
    string state = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state += board[i][j];
        }
    }
    return state;
}

void TicTacToe::setBoardState(const string& state) {
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = state[idx++];
        }
    }
}
