class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        // i < j and nums[i] > nums[j] jump to j
        // i > j and nums[i] < nums[j] jump to j

        int n = nums.size();
        vector<int>minRight(n);
        vector<int>maxLeft(n);

        maxLeft[0] = nums[0];
        minRight[n-1] = nums[n-1];

        for (int i = 1; i < n; i++){
            maxLeft[i] = max(nums[i], maxLeft[i-1]);
        }

        for (int i = n-2; i >= 0; i--){
            minRight[i] = min(minRight[i+1], nums[i]);
        }

        vector<int>ans(n);

        ans[n-1] = maxLeft[n-1];

        for (int i = n-2; i >= 0; i--){
            if (maxLeft[i] <= minRight[i+1]){
                ans[i] = maxLeft[i];
            }
            else {
                ans[i] = ans[i+1];
            }
        }

        return ans;

    }
};