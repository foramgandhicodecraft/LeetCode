class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(nums, 0, -1, n, dp);
        
    }

private:
    int f(vector<int>&nums, int index, int prev_ind, int n, vector<vector<int>>&dp){
        if (index == n)
          return 0;

        if (dp[index][prev_ind+1] != -1)  return dp[index][prev_ind+1];

        int not_take = 0 + f(nums, index+1, prev_ind, n, dp);

        int take = 0;
        if (prev_ind == -1 || nums[index] > nums[prev_ind]){
            take = 1 + f(nums,index+1, index, n, dp);
        }
       return dp[index][prev_ind+1] = max(take, not_take);
    }
};