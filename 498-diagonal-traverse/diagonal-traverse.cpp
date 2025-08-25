class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < n; j++){
        //         if (i%2 == 0){
        //             int k = 0;
        //             while (i-k >= 0){
        //                 ans.push_back(mat[i-k][j]);
        //                 k++;
        //             }
        //         } else {
        //             int k = 0;
        //             while (i-k >,)
        //         }
        //     }
        // }

        int col = 0;
        int row = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int>res;

        while (res.size() < m*n){
            res.push_back(mat[row][col]);

            if ((col + row) % 2 == 0){
                if (col == n-1) row++;
                else if (row == 0) col++;
                
                else {
                    row--;
                    col++;
                }

            }
            
            else {
               if (row == m-1) col++;
               else if (col == 0) row++;
                else {
                    row++;
                    col--;
                } 
            }
        }

        return res;
    }
};