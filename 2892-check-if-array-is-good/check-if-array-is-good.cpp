class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int current = n-1;

        if (nums[n-1] != current){
            return false;
        }
        else if (nums[n-2] != current){
            return false;
        }
        else {
            for (int i = n-3; i >= 0; i--){
                current--;
                if (nums[i] != current){
                    return false;
                }
            }
        }

        return true;
    }
};