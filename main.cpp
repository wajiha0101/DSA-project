#include <iostream>
#include "Sudoku-db.h"  
#include"Sudoku.h"
#include "tic tac toe.h"  
#include "eightpuzzle.h"   
#include "eightpuzzle-db.h"
using namespace std;

void displayMenu() {
    cout << "Welcome to MindMaze Mini!" << std::endl;
    cout << "1. Play Sudoku" << endl;
    cout << "2. Play Tic Tac Toe" << endl;
    cout << "3. Solve 8 Puzzle" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose a game (1-4): ";
}


//void playSudoku(SudokuDB& db) {
//    vector<string> puzzles = db.getAllPuzzleNames();
//    if (puzzles.empty()) {
//        cout << "No puzzles in the database.\n";
//        return;
//    }
//
//    cout << "Available puzzles:\n";
//    for (size_t i = 0; i < puzzles.size(); ++i) {
//        cout << i + 1 << ". " << puzzles[i] << "\n";
//    }
//
//    int choice;
//    cout << "Enter the number of the puzzle to load: ";
//    cin >> choice;
//
//    if (choice < 1 || choice > puzzles.size()) {
//        cout << "Invalid choice.\n";
//        return;
//    }
//
//    string selectedPuzzle = puzzles[choice - 1];
//    string puzzleData = db.loadPuzzle(selectedPuzzle);
//
//    if (puzzleData.empty()) {
//        cout << "Puzzle not found in the database.\n";
//        return;
//    }
//
//    db.stringToBoard(puzzleData, grid);
//    cout << "\nPuzzle Loaded. Start solving:\n";
//
//    userSolve();  // Only this: user manually enters values in the grid
//}


void playSudoku() {
    int easy[9][9] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    int hard[9][9] = {
        {0,0,0, 0,0,0, 0,1,2},
        {0,0,0, 0,3,5, 0,0,0},
        {0,0,0, 7,0,0, 0,0,0},

        {0,0,0, 6,0,0, 0,0,3},
        {0,0,0, 0,9,0, 0,0,0},
        {8,0,0, 0,0,4, 0,0,0},

        {0,0,0, 0,0,9, 0,0,0},
        {0,0,0, 4,1,0, 0,0,0},
        {2,7,0, 0,0,0, 0,0,0}
    };

    cout << "\nChoose a Sudoku Puzzle:\n";
    cout << "1. Easy\n";
    cout << "2. Hard\n";
    cout << "Enter choice (1-2): ";
    int puzzleChoice;
    cin >> puzzleChoice;

    if (puzzleChoice == 1)
        memcpy(grid, easy, sizeof(grid));
    else if (puzzleChoice == 2)
        memcpy(grid, hard, sizeof(grid));
    else {
        cout << "Invalid choice.\n";
        return;
    }

    cout << "\nPuzzle Loaded. Start solving:\n";
    userSolve();
}





void playTicTacToe() {
    TicTacToe game;
    game.printBoard();
    game.playGame();
}

void solveEightPuzzle() {
    EightPuzzle puzzleSolver;

    vector<vector<int>> board1 = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    vector<vector<int>> board2 = {
        {1, 2, 3},
        {0, 4, 6},
        {7, 5, 8}
    };

    vector<vector<int>> board3 = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    cout << "\nChoose a Puzzle Board:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "Enter choice (1-3): ";
    int boardChoice;
    cin >> boardChoice;

    vector<vector<int>> selectedBoard;
    switch (boardChoice) {
        case 1: selectedBoard = board1; break;
        case 2: selectedBoard = board2; break;
        case 3: selectedBoard = board3; break;
        default: 
            cout << "Invalid board choice.\n";
            return;
    }

    cout << "\nChoose 8 Puzzle Mode:\n";
    cout << "1. Play Yourself\n";
    cout << "2. Watch AI Solve\n";
    cout << "Enter choice (1-2): ";
    int modeChoice;
    cin >> modeChoice;

    if (modeChoice == 1)
        puzzleSolver.playPuzzle(selectedBoard);  
    else if (modeChoice == 2)
        puzzleSolver.solvePuzzle(selectedBoard); 
    else
        cout << "Invalid mode.\n";
}



int main() {
    SudokuDB sudokuDb;
    
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            playSudoku();
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
