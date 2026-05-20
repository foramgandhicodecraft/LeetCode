class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int>s;
        unordered_map<int, int>m;
        int n = nums.size();

        for (int num:nums){
            m[num] += 1;
        }

        for (auto key:m){
            if (key.second > n/3){
                s.insert(key.first);
            }
        }

        vector<int>ans(s.begin(), s.end());

        return ans;
    }
};