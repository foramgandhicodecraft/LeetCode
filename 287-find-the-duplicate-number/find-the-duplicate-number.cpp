class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // floyd's cycle detection - tortoise and hare (in arrays)
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};