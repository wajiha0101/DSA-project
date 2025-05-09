#include "EightPuzzle-db.h"
#include <iostream>

EightPuzzleDB::EightPuzzleDB() {
    // Constructor
}

std::vector<int> EightPuzzleDB::loadPuzzle(const std::string& difficulty) {
    if (difficulty == "easy") {
        return { 1, 2, 3, 4, 5, 6, 7, 8, 0 };  // Solved state
    }
    else if (difficulty == "medium") {
        return { 1, 2, 3, 4, 0, 6, 7, 5, 8 };  // Mixed state
    }
    else if (difficulty == "hard") {
        return { 8, 6, 7, 2, 5, 4, 3, 0, 1 };  // Hardest known solvable
    }
    else {
        return { 0, 0, 0, 0, 0, 0, 0, 0, 0 };  // Empty / invalid fallback
    }
}

void EightPuzzleDB::savePuzzle(const std::string& puzzleName, const std::vector<int>& puzzleState) {
    std::cout << "Saving puzzle state for: " << puzzleName << std::endl;
    // Optional: save to file/db if needed
}
