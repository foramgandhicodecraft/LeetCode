class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;
        vector<vector<int>>ans;
        int n = candidates.size();
        f (ans, arr, candidates, target, 0, n);
        return ans;
    }

    void f (vector<vector<int>>&ans, vector<int>&arr, vector<int>& candidates, int target, int i, int n) {
        if (i >= n) {
            if (target == 0) {
                ans.push_back(arr);
            }
            return;
        }

        if (candidates[i] <= target) {
            arr.push_back(candidates[i]);
            f(ans,arr,candidates, target-candidates[i], i, n);
            arr.pop_back();
        }

        f(ans, arr, candidates, target, i+1, n);

    }
};