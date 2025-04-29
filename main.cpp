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
    vector<string> puzzles = db.getAllPuzzleNames();
    if (puzzles.empty()) {
        cout << "No puzzles in the database.\n";
        return;
    }

    cout << "Available puzzles:\n";
    for (size_t i = 0; i < puzzles.size(); ++i) {
        cout << i + 1 << ". " << puzzles[i] << "\n";
    }

    int choice;
    cout << "Enter the number of the puzzle to load: ";
    cin >> choice;

    if (choice < 1 || choice > puzzles.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    string selectedPuzzle = puzzles[choice - 1];
    string puzzleData = db.loadPuzzle(selectedPuzzle);

    if (puzzleData.empty()) {
        cout << "Puzzle not found in the database.\n";
        return;
    }

    db.stringToBoard(puzzleData, grid);
    cout << "\nPuzzle Loaded. Start solving:\n";

    userSolve();  // Only this: user manually enters values in the grid
}

void seedSudokuPuzzles(SudokuDB& db) {
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

    db.savePuzzle("easy1", db.boardToString(easy));
    db.savePuzzle("hard1", db.boardToString(hard));
    cout << "Seeded DB with easy1 and hard1 puzzles.\n";
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
