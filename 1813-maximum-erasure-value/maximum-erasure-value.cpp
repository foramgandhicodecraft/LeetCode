class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        set<int>s;
        int max_sum = 0;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++){
            while (s.find(nums[right]) != s.end() && left < right){
                s.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            s.insert(nums[right]);
            sum += nums[right];

            max_sum = max(sum, max_sum);
        }

        return max_sum;
    }
};