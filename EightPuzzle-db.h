#pragma once
#include <string>
#include <vector>

class EightPuzzleDB {
public:
    EightPuzzleDB();

    // Loads a flat 1D puzzle state
    std::vector<int> loadPuzzle(const std::string& difficulty);

    // Saves a flat 1D puzzle state
    void savePuzzle(const std::string& puzzleName, const std::vector<int>& puzzleState);
};
