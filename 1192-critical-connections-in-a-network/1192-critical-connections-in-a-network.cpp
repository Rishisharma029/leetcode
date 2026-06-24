class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    vector<int> disc, low;
    int timer = 0;

    void dfs(int u, int parent) {
        disc[u] = low[u] = ++timer;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!disc[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    ans.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        disc.assign(n, 0);
        low.assign(n, 0);

        for (auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        return ans;
    }
};