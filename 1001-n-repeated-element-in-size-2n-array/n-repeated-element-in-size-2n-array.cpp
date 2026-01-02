class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int target = nums.size() / 2;
        map<int, int>m;

        for (int num:nums){
            m[num]++;
        }

        for (auto key:m){
            if (key.second == target){
                return key.first;
            }
        }

        return 0;
    }
};