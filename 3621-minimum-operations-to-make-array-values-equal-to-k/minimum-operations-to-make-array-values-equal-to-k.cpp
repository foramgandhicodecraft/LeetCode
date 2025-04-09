class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // if num in nums < k, not possible
        for (int num:nums){
            if (num < k){
                return -1;
            }
        }

        set<int>s;
        int ans = 0;
        for (int num:nums){
            if (s.find(num) == s.end() && num > k){
                s.insert(num);
                ans++;
            }
        }

        return ans;
    }
};