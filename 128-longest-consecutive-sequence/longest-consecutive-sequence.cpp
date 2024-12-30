class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        unordered_set<int>setNums(nums.begin(),nums.end());
        int longest_streak = 0;
        int currentNums;
        int current_streak;

        for (int i:setNums){
            if (setNums.find(i-1) == setNums.end()){
                currentNums = i;
                current_streak = 1;

                while(setNums.find(currentNums+1) != setNums.end()){
                   currentNums++;
                   current_streak++;
                }

                if (current_streak > longest_streak){
                   longest_streak = current_streak;
                }

            }
        }

        return longest_streak;
    }
};