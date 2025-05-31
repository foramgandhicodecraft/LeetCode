class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        combination(0, target, ds, candidates, ans);
        return ans;
    }

private:
    void combination(int index, int target, vector<int>ds, vector<int>&arr, vector<vector<int>>& ans){
        if (index == arr.size()){
            if (target == 0)
              ans.push_back(ds);
            // always return back to carry forward the right part of the recursion
            return;
        }

        //pick up the element
        if (arr[index] <= target){
            ds.push_back(arr[index]);
            combination(index, target-arr[index], ds, arr, ans);
            // to remove the last element from ds as it needs to be removed for the case which does not take the element at arr[index]
            ds.pop_back();
        }

        // do not pick the element
        combination(index+1, target, ds, arr, ans);
    }
};