#pragma once
#include <string>
#include <vector>

using namespace std;
class EightPuzzleDB {
public:
    EightPuzzleDB();

    // Returns a flat 1D vector<int> of puzzle tiles
    vector<int> loadPuzzle(const string& difficulty);

    // Placeholder if you want to support saving later
    void savePuzzle(const string& puzzleName, const vector<int>& puzzleState);
};
