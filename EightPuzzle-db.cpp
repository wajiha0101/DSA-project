#include "EightPuzzle-db.h"
#include <iostream>
using namespace std;

EightPuzzleDB::EightPuzzleDB() {
    // Constructor
}

std::vector<int> EightPuzzleDB::loadPuzzle(const std::string& difficulty) {
    if (difficulty == "easy") {
        return { 1, 2, 3, 4, 5, 6, 7, 8, 0 }; // Solved
    }
    else if (difficulty == "medium") {
        return { 1, 2, 3, 4, 0, 6, 7, 5, 8 }; // Medium
    }
    else if (difficulty == "hard") {
        return { 8, 6, 7, 2, 5, 4, 3, 0, 1 }; // Tough
    }
    else {
        return { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // Empty
    }
}
//vector<vector<int>> EightPuzzleDB::loadPuzzle(const string& puzzleName) {
//    cout << "Loading Eight Puzzle: " << puzzleName << "\n";
//    return {
//        {1, 2, 3},
//        {4, 0, 6},
//        {7, 5, 8}
//    };
//}

void EightPuzzleDB::savePuzzle(const string& puzzleName, const vector<int>& puzzleState) {
    cout << "Saving Eight Puzzle: " << puzzleName << "\n";
}

