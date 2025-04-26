#pragma once
#include <string>
#include <vector>
using namespace std;

class EightPuzzleDB {
public:
    EightPuzzleDB();
    vector<vector<int>> loadPuzzle(const string& puzzleName);
    void savePuzzle(const string& puzzleName, const vector<vector<int>>& puzzleState);
};



