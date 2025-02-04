class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int q = 0;
        int p;
        int count = 1;

        for (p = 0; p < nums.size(); p++){
            if (nums[p] != nums[q]){
                q++;
                nums[q] = nums[p];
            }
        }

        return q+1;
    }

};