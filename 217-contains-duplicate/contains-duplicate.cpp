class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>appear;

        for (int i = 0; i < nums.size(); i++){
            if (appear.find(nums[i]) != appear.end())
              return true;

            appear.insert(nums[i]);
        }

        return false;
    }
};