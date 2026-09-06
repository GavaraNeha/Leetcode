class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);

        for (auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> ans;
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int parent) {
            disc[u] = low[u] = timer++;

            for (int v : graph[u]) {
                if (v == parent)
                    continue;

                if (disc[v] == -1) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);

                    if (low[v] > disc[u])
                        ans.push_back({u, v});
                } else {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };

        dfs(0, -1);

        return ans;
    }
};