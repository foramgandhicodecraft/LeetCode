class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        int l,r,sum;
        for (int i = 0; i < nums.size()-2; i++){
            l = i+1;
            r = nums.size()-1;
            while (l < r){
                sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                  l++;
                else if (sum > 0)
                  r--;
                else{
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
            }
        }

        vector<vector<int>>ans(s.begin(), s.end());

        return ans;
    }
};