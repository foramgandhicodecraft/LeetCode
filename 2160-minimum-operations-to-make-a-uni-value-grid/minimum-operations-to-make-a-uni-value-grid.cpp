class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // if (grid.empty()){
        //     return -1;
        // }
        // if (grid.size() == 1){
        //     return 0;
        // }

        int m = grid.size();
        int n = grid[0].size();
        // int not_divisible = 0,divisible = 0;
        // int max_divide = 0;

        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < n; j++){
        //         if (grid[i][j] % x != 0){
        //             not_divisible++;
        //         }else{
        //             divisible++;
        //         }
        //     }
        // }

        // // either all are divisible or no one is divisible
        // if (divisible == m*n || not_divisible == m*n){

        //  for (int i = 0; i < m; i++){
        //     for (int j= 0; j < n; j++){
        //         if ((grid[i][j] / x) > max_divide){
        //             max_divide = grid[i][j]/x;
        //         }
        //     }
        //  }

        //  return max_divide;
        // }

        // else{
        //     return -1;
        // }

        vector<int>nums;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int remainder = nums[0] % x;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] % x != remainder){
                return -1;
            }
        }

        int median = nums[nums.size() / 2];
        int operations = 0;

        for (int num:nums){
            operations += abs(num - median) / x;
        }

        return operations;

    }
};