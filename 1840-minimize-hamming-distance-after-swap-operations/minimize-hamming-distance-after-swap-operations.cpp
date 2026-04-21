class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[py] = px;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        for (int i = 0; i < n; i++) parent[i] = i;

        // build components
        for (auto &e : allowedSwaps) {
            unite(e[0], e[1]);
        }

        unordered_map<int, unordered_map<int, int>> mp;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            mp[root][source[i]]++;  
        }

        int hamming = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i);

            if (mp[root][target[i]] > 0) {
                mp[root][target[i]]--;
            } else {
                hamming++;
            }
        }

        return hamming;
    }
};