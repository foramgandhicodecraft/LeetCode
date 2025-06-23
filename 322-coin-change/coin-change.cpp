class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp (n, vector<int>(amount+1, -1));
        int ans = f(coins, amount, n-1, dp);
        if (ans >= 1e9){
            return -1;
        }else{
            return ans;
        }
        return 0;
    }

    int f(vector<int>&nums, int target, int index, vector<vector<int>>& dp){
        if (index == 0){
            if (target % nums[0] == 0){ // calculate how many nums[0] will be needed
                return target / nums[0];
            } else{
                return 1e9; // some large value
            }
        }

        if (target == 0) // when target is reached no further coins are requires
          return 0;

        if (dp[index][target] != -1)
          return dp[index][target];

        int not_take = f(nums, target, index-1, dp);
        int take = 1e9;

        if (nums[index] <= target){
            take = 1 + f(nums, target-nums[index], index, dp);
        }

        return dp[index][target] = min(take,not_take);
    }
};