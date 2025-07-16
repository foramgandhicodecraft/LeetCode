class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // int max_size = -1;
        // vector<int> current;
        // vector<vector<int>> dp()
        // f(nums, target, 0, 0, max_size, current);
        // return max_size;

        vector<int>dp(target+1, -1);

        dp[0] = 0;

        for (int num:nums){

            for (int j = target; j >= num; j--){
                if (dp[j-num] != -1){
                    dp[j] = max(dp[j], dp[j-num]+1);
                }
            }
        }

        return dp[target];
    }

    // void f(vector<int>& nums, int target, int i, int sum, int& max_size, vector<int>& current) {
    //     if (sum == target) {
    //         max_size = max(max_size, (int)current.size());
    //     }

    //     if (i >= nums.size()) return;

    //     // take
    //     if (nums[i] <= target - sum) {
    //         current.push_back(nums[i]);
    //         f(nums, target, i + 1, sum + nums[i], max_size, current);
    //         current.pop_back();
    //     }

    //     // not take
    //     f(nums, target, i + 1, sum, max_size, current);
    // }
};
