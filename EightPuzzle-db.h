#pragma once
#include <string>
#include <vector>

class EightPuzzleDB {
public:
    EightPuzzleDB();

    // Returns a flat 1D vector<int> of puzzle tiles
    std::vector<int> loadPuzzle(const std::string& difficulty);

    // Placeholder if you want to support saving later
    void savePuzzle(const std::string& puzzleName, const std::vector<int>& puzzleState);
};
