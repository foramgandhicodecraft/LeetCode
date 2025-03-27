class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int total_count = 0;
        int dominant;
        int i;
        int n = nums.size();
        unordered_map<int,int>m;
        for (i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }

        int target = nums.size()/2;

        for (auto it:m){
            if (it.second >= target){
            dominant = it.first;
        }
        }

        // count total number of dominant elements in the array
        for (i = 0; i < nums.size(); i++){
            if (nums[i] == dominant){
                total_count++;
            }
        }
        
        int left_count=0, right_count=0;
        int left_length = 0, right_length = 0;

        for (i = 0; i < nums.size(); i++){
            if (nums[i] == dominant){
                left_count++;
                right_count = total_count - left_count;
            }
            left_length = i+1;
            right_length = n - (i+1);

            if (left_count*2 > left_length && right_count*2 > right_length){
                return i;
            }
        }
        return -1;
    }
};