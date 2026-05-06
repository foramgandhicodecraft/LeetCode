class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        // first take transpose
        // stay at bottom of each column and calculate the nearest obstacle, stone or end point for each stone
        // plus 1 will be position of stone
        // do for each column

        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>>temp(n, vector<char>(m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                temp[i][j] = boxGrid[m - 1 - j][i];
            }
        }

        for (int i = 0; i < m; i++){
            int latest_j = n-1;
            for (int j = n-1; j >= 0; j--){
                if (temp[j][i] == '*'){
                    latest_j = j-1;
                }
                else if (temp[j][i] == '#'){
                    temp[latest_j][i] = '#';
                    if (j != latest_j){
                        temp[j][i] = '.';
                    }
                    latest_j--;
                }
            }
        }

        return temp;
    }
};
