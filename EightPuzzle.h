#pragma once
#include <vector>
#include <string>
using namespace std;

class EightPuzzle {
public:
    EightPuzzle();
    void solvePuzzle();
    void playPuzzle();
private:
    struct Node {
        vector<vector<int>> mat;
        int x, y;
        int cost;
        int level;
        string path;

        bool operator>(const Node& other) const;
    };

    static const int N = 3;
    vector<vector<int>> goal;

    int dx[4];
    int dy[4];
    char dir[4];

    int calculateHeuristic(vector<vector<int>>& mat);
    bool isValid(int x, int y);
};
