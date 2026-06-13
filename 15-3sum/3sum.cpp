class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < nums.size()-2; i++){

            if (i > 0 && nums[i] == nums[i-1]) continue;

            int low = i+1;
            int high = n-1;

            while (low < high){
                long long sum = (long long)nums[i] + (long long)nums[low] + nums[high];
                if (sum == 0){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low+1] == nums[low]) low++;
                    while (low < high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if (sum < 0) low++;
                else if (sum > 0) high--;
            }
        }

        return ans;
    }
};