class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int>m;
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }
        for (int i = 0; i < nums.size(); i++){
            if (m[nums[i]] % 2)
              return false;
        }
        
        return true;
    }
};