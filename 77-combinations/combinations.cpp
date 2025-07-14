class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int>arr;
        vector<int>current;
        vector<vector<int>>ans;
        
        for (int i = 1; i <= n; i++){
            arr.push_back(i);
        }

        f(arr, 1, current, ans, k, n);

        return ans;
    }

private:
    void f (vector<int>&arr, int i, vector<int>&current,
        vector<vector<int>>&ans, int k, int n){

        if (current.size() == k){
            ans.push_back(current);
            return; 
        }

        for (int index = i; index <= n; index++){
            current.push_back(index);
            f (arr, index+1, current, ans, k, n);
            current.pop_back();
        }

    }
};