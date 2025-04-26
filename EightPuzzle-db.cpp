#include "EightPuzzle-db.h"
#include <iostream>
using namespace std;

EightPuzzleDB::EightPuzzleDB() {
    // Constructor
}

vector<vector<int>> EightPuzzleDB::loadPuzzle(const string& puzzleName) {
    cout << "Loading Eight Puzzle: " << puzzleName << "\n";
    return {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };
}

void EightPuzzleDB::savePuzzle(const string& puzzleName, const vector<vector<int>>& puzzleState) {
    cout << "Saving Eight Puzzle: " << puzzleName << "\n";
}
