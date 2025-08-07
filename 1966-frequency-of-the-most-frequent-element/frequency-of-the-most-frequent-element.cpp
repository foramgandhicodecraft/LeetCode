class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // int count = 0;

        // map<int, int>m;

        // for (int i = 0; i < nums.size()-1; i++){
        //     m[nums[i+1]-nums[i]] = i;
        // }

        // for (auto key:m){
        //     if (key.first <= k){
        //         count++;
        //         nums[key.second] = k;
        //     }
        // }

        // return count+1;



        int ans = INT_MIN;
        // int current_count = 1;
        // int restore = k;

        // for (int i = nums.size() - 1; i >= 1; i--) {
        //     for (int j = i - 1; j >= 0; j--) {
        //         if ((nums[i] - nums[j]) >= k) {
        //             current_count++;
        //             k -= nums[i] - nums[j];
        //         } else {
        //             break;
        //         }
        //     }
        //     k = restore;
        //     ans = max(ans, current_count);
        //     current_count = 1;
        // }

        // return ans;

        int l = 0;
        int r = 0;
        long long sum = 0;
        // while (r < nums.size()){

        //     long long require = (long long)nums[r]*(r-l+1) - sum;

        //     if (require <= k){
        //         sum += nums[r];
        //         r++;
        //     } else {
        //         sum -= nums[l];
        //         if (l < r){
        //             l++;
        //         }
        //     }

        //     ans = max(ans, r-l);
        // }

        for (r = 0; r < nums.size(); r++){
            sum += nums[r];
            long long required = (long long)nums[r]*(r-l+1);

            while (l < r && required- sum > k){
                sum -= nums[l];
                l++;
                required = (long long)nums[r]*(r-l+1);
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }

};