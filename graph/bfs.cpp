#include "graph.h"

using namespace std;

int bfs(vector<vector<int>> &map, int n, int m, int startX, int startY, int endX, int endY) {
    if (startX == endX && startY == endY) {
        return 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int steps = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        int size = q.size();
        steps++;
        for (int i = 0; i < size; i++) {
            pair<int, int> current = q.front();
            int x = current.first;
            int y = current.second;
            q.pop();

            for (const pair<int, int> &direction : directions) {
                int dx = direction.first;
                int dy = direction.second;
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                    map[newX][newY] == 0 && !visited[newX][newY]) {
                    if (newX == endX && newY == endY) {
                        return steps;
                    }
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

    return -1; // No path found
}