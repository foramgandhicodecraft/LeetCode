class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small;
        vector<int>big;
        vector<int>Pivot;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < pivot)
              small.push_back(nums[i]);
            else if (nums[i] == pivot)
              Pivot.push_back(nums[i]);
            else
              big.push_back(nums[i]);
        }

        vector<int>ans;
        ans.insert(ans.end(),small.begin(),small.end());
        ans.insert(ans.end(),Pivot.begin(),Pivot.end());
        ans.insert(ans.end(),big.begin(),big.end());

        return ans;
    }
};