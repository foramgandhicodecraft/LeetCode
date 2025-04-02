class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max_value = 0;

        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                for (int k = j+1; k < nums.size(); k++){
                    long long current;
                    current = 1LL * (nums[i] - nums[j]) * nums[k];

                    if (current > max_value){
                        max_value = current;
                    }
                }
            }
        }

        if (max_value < 0){
            return 0;
        }
        return max_value;
    }
};