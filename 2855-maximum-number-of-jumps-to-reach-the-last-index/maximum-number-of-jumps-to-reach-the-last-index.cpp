class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,0);

        for (int i = 0; i < n-1; i++){
            if (i > 0 && dp[i] == 0){
                continue;
            }
            for (int j = i+1; j < n; j++){
                int num = nums[j]-nums[i];
                if (num >= -target && num <= target){
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }

        if (dp[n-1] == 0){
            return -1;
        }

        return dp[n-1];
    }
};