class Solution {
public:
    
    int mod = 1000000000+7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = queries[0].size();

        for (int i = 0; i < n; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            long long v = queries[i][3];
            int idx = l;
            while (idx <= r){
                nums[idx] = (nums[idx]*v)%mod;
                idx += k;
            }
        }

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++){
            ans = ans^nums[i];
        }

        return ans;
        
    }
};