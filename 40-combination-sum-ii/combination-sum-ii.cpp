class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end());
        combination(0, target, ds, candidates, ans);
        return ans;
    }

private:
    void combination(int index, int target, vector<int>&ds, vector<int>& arr, vector<vector<int>>& ans){
       
        if (target == 0){
            ans.push_back(ds);
            return;
        }
        
        for (int i = index; i < arr.size(); i++){
            if (arr[i] > target) 
              break;

            if (i != index && arr[i] == arr[i-1])  continue;
            
            ds.push_back(arr[i]);
            combination(i+1, target-arr[i], ds, arr, ans);
            ds.pop_back();
        }
    }
};