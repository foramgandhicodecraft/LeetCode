class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int left = 0;
        int max_length = INT_MIN;

        map<pair<int, int>, int>m;

        if (find(nums.begin(), nums.end(), 1) == nums.end()) return 0;

        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0){
                if (right+1 < nums.size()){
                    left = right+1;
                }
                
            }

            if (nums[right] != 0){
                max_length = max(max_length, right-left+1);
            }
            
        }

        return max_length;
    }
};