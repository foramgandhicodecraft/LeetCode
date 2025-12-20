class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int longest_streak = 0;
        int current_streak = 0;
        set<int>s(nums.begin(), nums.end());
        int current_num = nums[0];

        for (int num:s){
            if (s.find(num-1) == s.end()){
                current_streak = 1;
                current_num = num;
            }
            while (s.find(current_num+1) != s.end()){
                current_streak++;
                current_num++;
            }

            if (current_streak > longest_streak){
                longest_streak = current_streak;
            }
        }

        return longest_streak;
    }
};