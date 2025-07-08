class Solution {
public:
    int jump(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(), -1));
        // return calc(nums, 0, 0, dp);
        int i = 0;
        int l = 0,r = 0;
        int jump = 0;

        while (r < nums.size()-1){
            int farthest = 0;


            for (int j = l; j <= r; j++){
                farthest = max(j+nums[j], farthest);
            }
            l = r+1;
            r = farthest;
            jump++;
        }

        return jump;
    }

    // int calc(vector<int>&nums, int i, int jump, vector<vector<int>>&dp){

    //     if (i >= nums.size()-1)
    //      return jump;

    //     if (dp[i][jump] != -1) return dp[i][jump];

    //     int mini = INT_MAX;

    //     for (int j = 1; j <= nums[i]; j++){
    //         mini = min(mini, calc(nums, i+j, jump+1, dp));
            
    //     }

    //     return dp[i][jump] = mini;


        
    // }
};