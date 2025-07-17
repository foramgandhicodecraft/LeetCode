class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        vector<vector<int>>dp(k+1, vector<int>(k+1, 0));
        int ans = 0;

        for (int num:nums){
            int currentMod = num % k;

            for (int mod = 0; mod <= k; mod++){
                dp[mod][currentMod] = dp[currentMod][mod] + 1;
                ans = max(ans, dp[mod][currentMod]);
            }
        }

        return ans;

        
    }
};