class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int province = 0;

    int find (int x){
        if (x == parent[x]){
            return parent[x];
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rank.resize(n,0);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (isConnected[i][j] == 1){
                    Union(i,j);
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (parent[i] == i){
                province++;
            }
        }

        return province;

    }
};