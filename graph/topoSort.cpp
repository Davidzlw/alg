#include "graph.h"

using namespace std;

vector<int> topoSort(int n, vector<vector<int>> prerequisites) {
    vector<int> result;
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (const auto &requirement : prerequisites) {
        int node = requirement[0];
        int prerequisite = requirement[1];
        graph[prerequisite].push_back(node);
        indegree[node]++;
    }

    queue<int> ready;
    for (int node = 0; node < n; node++) {
        if (indegree[node] == 0) {
            ready.push(node);
        }
    }

    while (!ready.empty()) {
        int node = ready.front();
        ready.pop();
        result.push_back(node);
        for (int next : graph[node]) {
            if (--indegree[next] == 0) {
                ready.push(next);
            }
        }
    }

    if (result.size() != static_cast<size_t>(n)) {
        result.clear();
    }
    return result;
}

void test_toposort() {
    vector<pair<int, vector<vector<int>>>> cases = {
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}},
        {3, {{0, 2}}},
        {3, {{0, 1}, {1, 2}, {2, 0}}},
        {4, {}},
        {3, {{1, 0}, {1, 0}}},
    };

    for (const auto &testCase : cases) {
        int n = testCase.first;
        const auto &prerequisites = testCase.second;
        vector<int> order = topoSort(n, prerequisites);
        cout << "n=" << n << ", prerequisites=" << prerequisites.size()
            << " -> ";
        if (order.empty()) {
            cout << "no topological order";
        } else {
            for (int node : order) {
                cout << node << " ";
            }
        }
        cout << '\n';
    }
}