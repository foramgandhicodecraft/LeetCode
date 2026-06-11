class Solution {
public:

    long long MOD = 1e9+7;

    long long power(long long base, long long exp) {
        if (exp == 0){
            return 1;
        }
        long long half = power(base, exp/2);
        long long result = (half*half)%MOD;

        if (exp%2 != 0){
            result = (result*base) % MOD;
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

        return power(2, d-1);
    }
};