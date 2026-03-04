class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>>probable;
        int ans = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1){
                    probable.push_back({i,j});
                }
            }
        }

        for (int i = 0; i < probable.size(); i++){
            bool valid = true;
            for (int row = 0; row < m; row++){
                if (row != probable[i].first && mat[row][probable[i].second] != 0){
                    valid = false;
                    break;
                }
            }
            for (int col = 0; col < n; col++){
                if (col != probable[i].second && mat[probable[i].first][col] != 0){
                    valid = false;
                    break;
                }
            }

            if (valid){
                ans++;
            }

        }

        return ans;
    }
};