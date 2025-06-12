class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_max = nums[0];
        int current_min = nums[0];
        int global_max = nums[0];

        for (int i = 1; i < nums.size(); i++){
            int temp_max = current_max;
            int temp_min = current_min;

            current_max = max(temp_max*nums[i], max(nums[i], temp_min*nums[i]));
            // negative*negative can make a larger positive
            current_min = min(nums[i], min(temp_min*nums[i], temp_max*nums[i]));

            global_max = max(global_max, current_max);
        }

        return global_max;
    }
};