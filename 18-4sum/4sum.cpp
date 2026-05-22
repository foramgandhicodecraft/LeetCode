class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;

        for (int i = 0; i < n-3; i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for (int j = i+1; j < n-2; j++){
                if (j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int low = j+1;
                int high = n-1;

                while (low < high){
                    long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];
                    if (sum == target){
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low+1] == nums[low]){
                            low++;
                        }
                        while (low < high && nums[high-1] == nums[high]){
                            high--;
                        }
                        low += 1;
                        high -= 1;
                    }
                    else if (sum < target){
                        low += 1;
                    }
                    else if (sum > target){
                        high -= 1;
                    }
                    
                }
            }
        }

        return ans;
    }
};