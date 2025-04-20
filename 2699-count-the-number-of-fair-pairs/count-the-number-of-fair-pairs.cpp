class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // sort(nums.begin(), nums.end());
        // int count = 0;
        // int low = 0;
        // int high = nums.size()-1;
        // set<vector<int>>occured;

        // while (low < high){
        //     if ((nums[low]+nums[high]) > upper){
        //         high--;
        //     }
        //     else if ((nums[low] + nums[high]) < lower){
        //         low++;
        //     }
        //     else{
                
        //         if (occured.find({nums[low], nums[high]}) == occured.end()){
        //             int low2 = low;
        //             int high2 = high;
        //             occured.insert({nums[low], nums[high]});
        //             count++;
        //             while (low2 < high2){
        //                 high2--;
        //                 if ((lower <= (nums[low2]+nums[high2])) && ((nums[low2]+nums[high2]) <= upper) && occured.find({nums[low2], nums[high2]}) == occured.end()){
        //                     occured.insert({nums[low2], nums[high2]});
        //                     count++;
        //                 }
        //             }
        //             high2 = high;
        //             while (low2 < high2){
        //                 low2++;
        //                 if ((lower <= (nums[low2]+nums[high2])) && ((nums[low2]+nums[high2]) <= upper) && occured.find({nums[low2], nums[high2]}) == occured.end()){
        //                     occured.insert({nums[low2], nums[high2]});
        //                     count++;
        //                 }
        //             }
        //         }
        //         low++;
        //         high--;
        //     }
        // }

        // return count;

        sort (nums.begin(), nums.end());
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++){
            int lwr = lower - nums[i];
            int upr = upper - nums[i];

            ans += upper_bound(nums.begin()+(i+1), nums.end(), upr) - lower_bound(nums.begin()+(i+1), nums.end(), lwr);

        }

        return ans;
    }
};