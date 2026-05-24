class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = f(coins, dp, n-1, amount);

        if (ans >= 1e9){
            return -1;
        }

        return ans;
    }

    int f (vector<int>nums, vector<vector<int>>&dp, int idx, int target){
        if (idx == 0){
            if (target % nums[0] == 0){
                return target/nums[0];
            }
            else {
                return 1e9;
            }
        }

        if (target == 0){
            return 0;
        }

        if (dp[idx][target] != -1){
            return dp[idx][target];
        }

        int not_take = f(nums, dp, idx-1, target);
        int take = 1e9;

        if (nums[idx] <= target){
            take = 1 + f(nums, dp, idx, target-nums[idx]);
        }

        return dp[idx][target] = min(take, not_take);
    }
};