class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if (find(nums.begin(), nums.end(), 0) == nums.end()){
            return nums.size()-1;
        }

        int left = 0;
        int n = nums.size();

        vector<pair<int, int>>arr;
        int right = 0;

        while (right < n){
            while (right < n && nums[right] == 0) right++;

            left = right;

            while (right < n && nums[right] == 1)right++;

            if (left < right){
                arr.push_back({left, right-1});
            }
        }

        int max_len = 0;

        for (auto key:arr){
            max_len = max(max_len, key.second-key.first+1);
        }

        for (auto i = 1; i < arr.size(); i++){
            if (arr[i].first - arr[i-1].second == 2){
                int current = (arr[i-1].second - arr[i-1].first + 1) + (arr[i].second - arr[i].first+1);
                max_len = max(max_len, current);
            }
        }

        return max_len;

    }
};