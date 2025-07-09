class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int result = 0;

        for (int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size()-1;

            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < target){
                    l++;
                }
                else if (sum > target){
                    r--;
                }
                else{
                    l++;
                }

                if (abs(target-sum) < ans){
                    ans = abs(target-sum);
                    result = sum;
                }
            }
        }

        return result;
    }

    
};