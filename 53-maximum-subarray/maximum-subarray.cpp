class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global = INT_MIN;
        int current_max = 0;
        
        for (int num:nums){
        
            current_max = max(current_max + num, num);
            global = max(global, current_max);
        }

        return global;

    }
};