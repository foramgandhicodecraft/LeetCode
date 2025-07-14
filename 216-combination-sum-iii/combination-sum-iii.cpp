class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        vector<int>current;
        vector<vector<int>>ans;

        for (int i = 1; i <= 9; i++){
            arr.push_back(i);
        }

        f(arr, k, n, current, ans, 0);
        return ans;
    }

private:
    void f (vector<int>&arr, int k, int target, vector<int>&current, vector<vector<int>>&ans, int index){
        if (target == 0 && current.size() == k){
            ans.push_back(current);
            return;
        }

        for (int i = index; i < arr.size(); i++){
            if (arr[i] <= target && current.size() < k){
                current.push_back(arr[i]);
                f (arr, k, target-arr[i], current, ans, i+1);
                current.pop_back();
            }
            
        }
    }
};