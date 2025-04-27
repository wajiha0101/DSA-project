#include <iostream>
#include "Sudoku-db.h"  
#include"Sudoku.h"
#include "tic tac toe.h"  
#include "eightpuzzle.h"   
#include "eightpuzzle-db.h"
using namespace std;

void displayMenu() {
    cout << "Welcome to Simplified Smart Puzzle Suite!" << std::endl;
    cout << "1. Play Sudoku" << endl;
    cout << "2. Play Tic Tac Toe" << endl;
    cout << "3. Solve 8 Puzzle" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose a game (1-4): ";
}


void playSudoku(SudokuDB& db) {
    string puzzleName;
    cout << "Enter the name of the Sudoku puzzle to load: ";
    cin >> puzzleName;

    string puzzleData = db.loadPuzzle(puzzleName);
    if (puzzleData.empty()) {
       cout << "Puzzle not found in the database!" << endl;
        return;
    }

    int board[9][9];
    db.stringToBoard(puzzleData, board);

    cout << "Loaded Sudoku Puzzle:" << endl;
    printboard();

    if (solvesudoku()) {
        cout << "\nSolved Sudoku Board:" << endl;
        printboard();

        string solvedPuzzleData = db.boardToString(board);
        db.savePuzzle(puzzleName + " Solved", solvedPuzzleData);
        cout << "Solved puzzle saved to database." << endl;
    }
    else {
       cout << "No solution exists for this Sudoku puzzle." << endl;
    }
}


void playTicTacToe() {
    TicTacToe game;
    game.printBoard();
    game.playGame();
}

void solveEightPuzzle() {
    EightPuzzle puzzleSolver;
    puzzleSolver.solvePuzzle();
}

int main() {
    SudokuDB sudokuDb;
    
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            playSudoku(sudokuDb);
            break;
        case 2:
            playTicTacToe();
            break;
        case 3:
            solveEightPuzzle();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        default:
           cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
