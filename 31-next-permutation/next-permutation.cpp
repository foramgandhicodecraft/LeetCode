class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;

        while (i >= 0 && nums[i] >= nums[i+1]){
            i -= 1;
        }

        if (i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while (nums[j] <= nums[i]){
            j--;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

        int left = i+1;
        int right = nums.size() - 1;

        while (left < right){
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }


    }
};