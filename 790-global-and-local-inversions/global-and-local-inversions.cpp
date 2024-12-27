class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int i;
        for (i = 0; i < nums.size(); i++){
            if (abs(nums[i]-i) > 1){
                return false;
            }
        }

        return true;
    }
};