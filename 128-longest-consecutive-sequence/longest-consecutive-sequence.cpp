class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        if (nums.size() == 1){
            return 1;
        }
        sort(nums.begin(), nums.end());
        int current_streak = 1;
        int current_element = nums[0];
        set<int>s;
        s.insert(nums[0]);
        int n = nums.size();
        int max_streak = 0;

        for (int i = 1; i < n; i++){
            if (s.find(nums[i]-1) != s.end() && nums[i] != current_element){
                current_streak++;
                current_element = nums[i];
                cout<<nums[i]<<":"<<current_streak<<endl;
                s.insert(nums[i]);
            }
            else {
                if (nums[i] != current_element && i > 0){
                    s.insert(nums[i]);
                current_streak = 1;
                current_element = nums[i];
                cout<<nums[i]<<":"<<current_streak<<endl;
                }
                
            }
            max_streak = max(max_streak, current_streak);
        }

        return max_streak;
    }
};