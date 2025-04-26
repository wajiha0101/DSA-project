#include "EightPuzzle.h"
#include "EightPuzzle-db.h"
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

EightPuzzle::EightPuzzle() {
    goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    dx[0] = 1; dy[0] = 0; dir[0] = 'D'; // Down
    dx[1] = 0; dy[1] = 1; dir[1] = 'R'; // Right
    dx[2] = -1; dy[2] = 0; dir[2] = 'U'; // Up
    dx[3] = 0; dy[3] = -1; dir[3] = 'L'; // Left
}

bool EightPuzzle::Node::operator>(const Node& other) const {
    return cost > other.cost;
}

int EightPuzzle::calculateHeuristic(vector<vector<int>>& mat) {
    int dist = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] != 0) {
                int val = mat[i][j];
                int targetX = (val - 1) / N;
                int targetY = (val - 1) % N;
                dist += abs(i - targetX) + abs(j - targetY);
            }
    return dist;
}

bool EightPuzzle::isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void EightPuzzle::solvePuzzle() {
    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    int x = 1, y = 1; // Blank position

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<vector<int>>> visited;

    Node root = { start, x, y, 0, 0, "" };
    root.cost = calculateHeuristic(start);
    pq.push(root);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.mat == goal) {
            cout << "\nPuzzle Solved in " << current.level << " moves\n";
            cout << "Moves: " << current.path << "\n";
            return;
        }

        visited.insert(current.mat);

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY)) {
                vector<vector<int>> newMat = current.mat;
                swap(newMat[current.x][current.y], newMat[newX][newY]);

                if (visited.find(newMat) == visited.end()) {
                    Node child = { newMat, newX, newY, 0, current.level + 1, current.path + dir[i] };
                    int h = calculateHeuristic(newMat);
                    child.cost = h + child.level;
                    pq.push(child);
                }
            }
        }
    }

    cout << "No solution found.\n";
}
