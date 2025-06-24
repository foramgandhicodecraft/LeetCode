class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);

        int prefix = 1;

        for (int left = 0; left < n; left++){
            result[left] = prefix;
            prefix *= nums[left];
        }

        int suffix = 1;

        for (int right = n-1; right >=0; right--){
            result[right] *= suffix;
            suffix *= nums[right];
        }

        return result;
        
        
    }
};