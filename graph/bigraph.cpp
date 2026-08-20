#include "graph.h"
#include <cassert>

using namespace std;

// Bipartite graph matching
class bigraph_matching {
private:
    vector<vector<int>> g;
    vector<int> pa;  // 匹配
    vector<int> pb;
    vector<int> vis;  // 访问
    int n, m;         // 两个点集中的顶点数量
    int dfn;          // 时间戳记
    int res;          // 匹配数

public:
    bigraph_matching(int _n, int _m) : n(_n), m(_m) {
        assert(0 <= n && 0 <= m);
        pa = vector<int>(n, -1);
        pb = vector<int>(m, -1);
        vis = vector<int>(n);
        g.resize(n);
        res = 0;
        dfn = 0;
    }

    void add(int from, int to) {
        assert(0 <= from && from < n && 0 <= to && to < m);
        g[from].push_back(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pb[u] = v;
                pa[v] = u;
                return true;
            }
        }
        for (int u : g[v]) {
            if (vis[pb[u]] != dfn && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            ++dfn;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (pa[i] == -1 && dfs(i)) {
                    ++cnt;
                }
            }
            if (cnt == 0) {
                break;
            }
            res += cnt;
        }
        return res;
    }
};

class hungarian {
public:
    struct Edge {
        int from;
        int to;
        int weight;

        Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    };

    vector<int> G[MAX_NUM]; /* G[i] 存储顶点 i 出发的边的编号 */
    vector<Edge> edges;
    typedef vector<int>::iterator iterator_t;
    int num_nodes;
    int num_left;
    int num_right;
    int num_edges;
    int matching[MAX_NUM]; /* 存储求解结果 */
    int check[MAX_NUM];

    bool dfs(int u) {
        for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) { // 对 u 的每个邻接点
            int v = edges[*i].to;
            if (!check[v]) {     // 要求不在交替路中
                check[v] = true; // 放入交替路
                if (matching[v] == -1 || dfs(matching[v])) {
                    // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                    matching[v] = u;
                    matching[u] = v;
                    return true;
                }
            }
        }
        return false; // 不存在增广路，返回失败
    }

    int solve() {
        int ans = 0;
        memset(matching, -1, sizeof(matching));
        for (int u = 0; u < num_left; ++u) {
            if (matching[u] == -1) {
                memset(check, 0, sizeof(check));
                if (dfs(u)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
