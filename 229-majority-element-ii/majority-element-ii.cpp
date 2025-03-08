class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int>ans;
        unordered_map<int,int>m;
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }
        for (int i = 0; i < nums.size(); i++){
            if (m[nums[i]] > n/3){
                ans.insert(nums[i]);
            }
        }
        vector<int>v(ans.begin(), ans.end());
        return v;

    }
};