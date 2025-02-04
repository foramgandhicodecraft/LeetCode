class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int max = sum;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1]){
                sum = sum+nums[i];
                if (sum > max){
                    max = sum;
                }
            }
            else{
                sum = nums[i];
            }
        }

        return max;
    }
};