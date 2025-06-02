class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        bool bingo = false;

        for (int i = 0; i < n; i++){
            if (i != nums[i]){
                return i;
                bingo = true;
            }
        }

        if (!bingo)
          return n;

        return 0;
    }
};