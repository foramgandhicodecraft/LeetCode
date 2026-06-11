class Solution {
public:

   static const int MOD = 1'000'000'007;

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int getDepth(unordered_map<int, vector<int>>&adj, int node, int parent){
        int depth = 0;

        for (auto ngbr:adj[node]){
            if (ngbr == parent) continue;
            depth = max(depth, getDepth(adj, ngbr, node)+1);
        }

        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for (auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = getDepth(adj, 1, -1);

        return power(2, d-1, MOD);
    }
};