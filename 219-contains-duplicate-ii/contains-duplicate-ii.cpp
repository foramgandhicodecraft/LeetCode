class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j;
        for (int i = 0; i < nums.size(); i++){
            if (i+k < nums.size())
               j = i+k;
            else 
              j = nums.size()-1;
            while (j > i){
                if (nums[i] == nums[j])
                  return true;
                j--;
            }

        }

        return false;

    }
};