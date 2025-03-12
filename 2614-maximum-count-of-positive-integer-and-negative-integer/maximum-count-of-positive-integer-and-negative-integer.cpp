class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count_pos = 0, count_neg = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                count_pos++;
            }
            if (nums[i] < 0){
                count_neg++;
            }
        }

        return max(count_pos, count_neg);
    }
};