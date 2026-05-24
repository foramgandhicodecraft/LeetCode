class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int q = 0;

        for (int p = 0; p < n; p++){
            if (nums[p] != nums[q]){
                q++;
                nums[q] = nums[p];
            }
        }

        return q+1;
    }
};