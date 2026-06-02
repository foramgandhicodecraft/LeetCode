class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;

        while (i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if (i == -1){
            return reverse(nums.begin(), nums.end());
        }

        for (int j = n-1; j > i; j--){
            if (nums[j] > nums[i]){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                break;
            }
        }

        reverse(nums.begin()+i+1, nums.end());

    }
};  