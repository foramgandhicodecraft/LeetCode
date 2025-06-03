class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        int k = 0;

        if (original.size() == 0)
          return ans;

        if (original.size() > m*n)
          return ans;

         if (original.size() < m*n)
          return ans;

        for (int i = 0; i < m; i++){
            vector<int>temp;
            for (int j = 0; j < n; j++){
                temp.push_back(original[k]);
                k++;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};