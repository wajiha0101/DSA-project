#include "Sudoku.h"
#include "Sudoku-db.h"
#include <iostream>

using namespace std;

void sudokuMenu() {
    SudokuDB db("sudoku.db");
    int choice;

    while (true) {
        cout << "\n--- Sudoku Menu ---\n";
        cout << "1. Solve New Sudoku\n";
        cout << "2. Save Current Sudoku\n";
        cout << "3. Load Sudoku Puzzle\n";
        cout << "4. Show Saved Puzzles\n";
        cout << "5. Exit Sudoku\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            inputValue();
            cout << "\nInput Sudoku Board:\n";
            printboard();
            if (solvesudoku()) {
                cout << "\nSolved Sudoku Board:\n";
                printboard();
            }
            else {
                cout << "No solution exists.\n";
            }
        }
        else if (choice == 2) {
            string name;
            cout << "Enter a name for this puzzle: ";
            cin >> name;
            string boardData = db.boardToString(grid);
            if (db.savePuzzle(name, boardData)) {
                cout << "Puzzle saved successfully.\n";
            }
            else {
                cout << "Failed to save puzzle.\n";
            }
        }
        else if (choice == 3) {
            string name;
            cout << "Enter the name of the puzzle to load: ";
            cin >> name;
            string data = db.loadPuzzle(name);
            if (!data.empty()) {
                db.stringToBoard(data, grid);
                cout << "Loaded Sudoku Puzzle:\n";
                printboard();
            }
            else {
                cout << "Puzzle not found.\n";
            }
        }
        else if (choice == 4) {
            vector<string> names = db.getAllPuzzleNames();
            cout << "\nSaved Puzzles:\n";
            for (const auto& n : names) {
                cout << "- " << n << "\n";
            }
        }
        else if (choice == 5) {
            cout << "Exiting Sudoku...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
