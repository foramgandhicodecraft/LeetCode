class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        subset(ans, ds, 0, n, nums);
        return ans;
    }

    void subset (vector<vector<int>>&ans, vector<int>ds, int index, int n, vector<int>nums){
        ans.push_back(ds);

        for (int i = index; i < n; i++){
            if (i != index && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            subset(ans, ds, i+1, n, nums);
            ds.pop_back();
        }
    }
};