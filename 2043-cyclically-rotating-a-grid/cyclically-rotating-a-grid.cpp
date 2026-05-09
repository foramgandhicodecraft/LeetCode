class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int k_original = k;
        
        // take one row and column and keep on going inside
        int row_low = 0;
        int row_high = m-1;
        int col_low = 0;
        int col_high = n-1;

        while ((row_low < row_high) && (col_low < col_high)){
            vector<int>current;
            // low column
            for (int i = row_low; i <= row_high; i++){
                current.push_back(grid[i][col_low]);
            }
            // high row
            for (int i = col_low+1; i <= col_high; i++){
                current.push_back(grid[row_high][i]);
            }
            // high column
            for (int i = row_high-1; i >= row_low; i--){
                current.push_back(grid[i][col_high]);
            }
            //low row
            for (int i = col_high-1; i > col_low; i--){
                current.push_back(grid[row_low][i]);
            }

            int length = current.size();
            k = k_original%length;
            while (k--){
                int remain = current[length-1];
                for (int i = length-2; i >= 0; i--){
                    current[i+1] = current[i];
                }
                current[0] = remain;
            }

            int j = 0;

            // low column
            for (int i = row_low; i <= row_high; i++){
                grid[i][col_low] = current[j];
                j++;
            }
            // high row
            for (int i = col_low+1; i <= col_high; i++){
                grid[row_high][i] = current[j];
                j++;
            }
            // high column
            for (int i = row_high-1; i >= row_low; i--){
                grid[i][col_high] = current[j];
                j++;
            }
            //low row
            for (int i = col_high-1; i > col_low; i--){
                grid[row_low][i] = current[j];
                j++;
            }

            row_low++;
            row_high--;
            col_low++;
            col_high--;

        }

        return grid;
    }
};