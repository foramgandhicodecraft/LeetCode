class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>>m;
        vector<int>ans(queries.size(), -1);
        int p = nums.size();
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }

        for (int  i = 0; i < queries.size(); i++){
            int num = nums[queries[i]];
            if (m[num].size() == 1){
                continue;
            }
            // binary search for finding index in map vector
            int target = queries[i];
            int low = 0;
            int high = m[num].size()-1;
            int array_index = -1;
            while (low <= high){
                int mid = (high-low)/2 +low;
                if (m[num][mid] < target){
                    low = mid+1;
                }
                else if (m[num][mid] > target){
                    high = mid-1;
                }
                else{
                    array_index = mid;
                    break;
                }
            }

            if (array_index == -1){
                continue;
            }

            int n = m[num].size();
            int next = m[num][(array_index + 1)%n];
            int prev = m[num][(array_index-1+n)%n];
            int right_distance = abs(next - target);
            int left_distance = abs(target - prev);
            right_distance = min(right_distance, p - right_distance);
            left_distance = min(left_distance, p - left_distance);
            ans[i] = min(left_distance, right_distance);
        }

        return ans;
    }
};