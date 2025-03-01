class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)
             count++;
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        while (count != 0 && j < nums.size()){
            nums[j] = 0;
            count--;
            j++;
        }
    }
};