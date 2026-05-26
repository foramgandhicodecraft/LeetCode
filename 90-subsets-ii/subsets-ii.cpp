class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        subset(nums,ans,0,ds);
        return ans;
    }

    void subset(vector<int>nums, vector<vector<int>>&ans, int idx, vector<int>&ds){
        ans.push_back(ds);
        for (int i = idx; i < nums.size(); i++){
            if (i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            subset(nums, ans, i+1, ds);
            ds.pop_back();
        }

    }
};