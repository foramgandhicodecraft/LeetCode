class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // for (int i = x; i <= m; i++){
        //     for (int j = y; j < k; j++){

        //     }
        // }
        int top = x;
        int bottom = x+k-1;
        
        while (top < bottom){
            for (int i = y; i <= y+k-1; i++){
                int temp = grid[top][i];
                grid[top][i] = grid[bottom][i];
                grid[bottom][i] = temp;
                // swap
                // temp = num1;
                // num1 = num2;
                // num2 = temp;

                
            }
            top++;
            bottom--;
        }

        return grid;
    }
};