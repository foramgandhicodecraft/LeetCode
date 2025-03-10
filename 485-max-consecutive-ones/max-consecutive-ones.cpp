class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        if (nums[0] == 1){
          count = 1;
          max_count = max(max_count, count);
        }
        
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == 1 && nums[i-1] == 1){
                count++;
                max_count = max(max_count, count);
            }
            else if (nums[i] == 1 && nums[i-1] != 1){
                count = 1;
                max_count = max(max_count, count);
            }
            else{
                count = 0;
                max_count = max(max_count, count);
            }
        }

        return max_count;
    }
};