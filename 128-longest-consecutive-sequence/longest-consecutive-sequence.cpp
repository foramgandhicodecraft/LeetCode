class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        set<int>s;
        int max_streak = 1;
        int current_streak = 1;

        for (int num:nums){
            s.insert(num);
        }

        for (int num:s){
            if (s.find(num+1) != s.end()){
                current_streak++;
                max_streak = max(max_streak, current_streak);
            }
            else {
                current_streak = 1;
            }
        }

        return max_streak;
    }
};