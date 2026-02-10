class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int count = 0;
        if (nums.size() == 0) return 0;

        for (int i = 0; i < nums.size()-1; i++){
            set<int>even;
            set<int>odd;
            if (nums[i] % 2 == 0){
                even.insert(nums[i]);
            }
            else{
                odd.insert(nums[i]);
            }

            for (int j = i+1; j < nums.size(); j++){
                if (nums[j] % 2 == 0){
                    if (even.find(nums[j]) == even.end()){
                        even.insert(nums[j]);
                    }
                }
                else {
                    if (odd.find(nums[j]) == odd.end()){
                        odd.insert(nums[j]);
                    }
                }

                if (odd.size() == even.size()){
                    count = max(count, j-i+1);
                }
            }

        }

        return count;
    }
};