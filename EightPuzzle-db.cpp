#include "EightPuzzle-db.h"
#include <iostream>

EightPuzzleDB::EightPuzzleDB() {
    // Constructor
}

std::vector<int> EightPuzzleDB::loadPuzzle(const std::string& difficulty) {
    if (difficulty == "easy") {
        return { 1, 2, 3, 4, 0, 6, 7, 5, 8 };
    }
    else if (difficulty == "medium") {
        return { 1, 2, 3, 0, 4, 6, 7, 5, 8 };
    }
    else if (difficulty == "hard") {
        return { 8, 6, 7, 2, 5, 4, 3, 0, 1 };
    }
    else {
        return { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // fallback
    }
}

void EightPuzzleDB::savePuzzle(const std::string& puzzleName, const std::vector<int>& puzzleState) {
    std::cout << "Saving puzzle '" << puzzleName << "' is not implemented.\n";
}
