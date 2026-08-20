#include "graph.h"

using namespace std;

class tree_array {
};

struct DAGNode {
    int index;
    vector<int> prev;
    vector<int> next;
};

class DFSSolver {
public:
    DFSSolver(vector<DAGNode>& ns, set<int>& sl)
        : n(ns.size()), nodes(ns), start_list(sl) {
        color = vector<int>(n, 0);
    }

    void dfs(int root) {
        color[root] = 1;
        for (auto child : nodes[root].next) {
            if (color[child] == 1) {
                hasCycle = true;
                break;
            } else if (color[child] == 0) {
                dfs(child);
            }
        }
        color[root] = 2;
    }

    bool solve() {
        for (auto start : start_list) {
            dfs(start);
            if (hasCycle) {
                return false;
            }
        }
        return true;
    }

public:
    int n;
    bool hasCycle = false;
    vector<DAGNode> nodes;
    set<int> start_list;
    vector<int> color;
};