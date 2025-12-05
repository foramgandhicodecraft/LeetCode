class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum_i = 0;
        int sum_e = 0;
        int count = 0;

        for (int i = 0; i < n-1; i++){
            sum_e += nums[i];
            for (int j = i+1; j < n; j++){
                sum_i += nums[j];
            }
            if ((sum_e - sum_i) % 2 == 0){
                count += 1;
            }
            sum_i = 0;
        }

        return count;
    }
};