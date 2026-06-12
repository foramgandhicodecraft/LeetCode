class Solution {
    static const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG + 1, vector<int>(n + 1, 1));
        vector<int> depth(n + 1, 0);

        // BFS from root (iterative — avoids stack overflow on deep trees)
        vector<bool> vis(n + 1, false);
        queue<int> bfs;
        bfs.push(1); vis[1] = true;
        while (!bfs.empty()) {
            int u = bfs.front(); bfs.pop();
            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                bfs.push(v);
            }
        }
        for (int k = 1; k <= LOG; k++)
            for (int v = 1; v <= n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k <= LOG; k++)
                if ((diff >> k) & 1) u = up[k][u];
            if (u == v) return u;
            for (int k = LOG; k >= 0; k--)
                if (up[k][u] != up[k][v]) { u = up[k][u]; v = up[k][v]; }
            return up[0][u];
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int d = depth[u] + depth[v] - 2 * depth[lca(u, v)];
            ans.push_back(d == 0 ? 0 : (int)power(2, d - 1));
        }
        return ans;
    }
};