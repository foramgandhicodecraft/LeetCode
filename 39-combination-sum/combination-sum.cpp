class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sum(0, nums, target, ds, ans);
        return ans;
    }

    void sum(int index, vector<int>&nums, int target, vector<int>ds, vector<vector<int>>&ans){
        if (index == nums.size()){
            if (target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // pick th element
        if (nums[index] <= target){
            ds.push_back(nums[index]);
            sum(index, nums, target-nums[index], ds, ans);
            ds.pop_back();
        }

        sum(index+1, nums, target, ds, ans);
    }
};