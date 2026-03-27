class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        // k = k % n;

        // while (k--){
        //     for (int i = 0; i < n; i++){
                
        //         if (i%2 == 0){
        //             int first = mat[i][0];
        //             for (int j = 1; j < m-1; j++){
        //                 mat[i][j-1] = mat[i][j];
        //             }
        //             mat[i][m-1] = first;
        //         }

        //         else{
        //             int last = mat[i][m-1];
        //             for (int j = m-1; j >= 0; j++){
        //                 mat[i][j] = mat[i][j-1];
        //             }
        //             mat[i][0] = last;
        //         }
        //     }
        // }

        if (k % m == 0){
            //cout<<"hello";
            return true;
        }
        else{
            
            for (int i = 0; i < n; i++){
                
                // int l = 0;
                for (int l = 0; l < m; l++){
                    if (mat[i][l] != mat[i][(l+k)%m]){
                        return false;
                    }
                    //l++;
                }
                
                
            }
        }

        return true;
    }
};