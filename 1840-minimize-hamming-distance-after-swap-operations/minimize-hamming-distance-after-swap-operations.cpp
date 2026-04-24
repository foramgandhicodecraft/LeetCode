class Solution {
public:
    vector<int> parent;
    vector<int>rank;

    int find(int x) {
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent){
            return;
        }

        if (rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if (rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else { 
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) parent[i] = i;

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