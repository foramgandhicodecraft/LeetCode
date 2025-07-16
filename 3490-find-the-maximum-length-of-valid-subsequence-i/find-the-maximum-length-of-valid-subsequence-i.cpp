class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // vector<int>current;
        // f (nums, 0, 0, current);
        vector<int>even;
        vector<int>odd;
        vector<int>odd_even;
        vector<int>even_odd;

        // all even or all odd
        for (int num:nums){
            if (num%2){
                odd.push_back(num);
            } else {
                even.push_back(num);
            }
        }

        int count = 0;
        int i = 0;
        while (i <= nums.size()-1){
            if (count % 2 == 0){
                while (i <= nums.size()-1 && nums[i] % 2 != 0){
                    i++;
                }
                if (i < nums.size()){
                even_odd.push_back(nums[i]);
                count++;
                i++;
                }
            }

            if (count % 2 != 0){ // odd index
                while (i <= nums.size()-1 && nums[i] % 2 == 0){
                    i++;
                }
                if (i < nums.size()){
                even_odd.push_back(nums[i]);
                count++;
                i++;
                }
            }
        }

        count = 0;
        i = 0;
        while (i <= nums.size()-1){
            if (count % 2 == 0){
                while (i <= nums.size()-1 && nums[i] % 2 == 0){
                    i++;
                }
                if (i < nums.size()){
                odd_even.push_back(nums[i]);
                count++;
                i++;
                }
            }

            if (count % 2 != 0){ // odd index
                while (i <= nums.size()-1 && nums[i] % 2 != 0){
                    i++;
                }
                if (i < nums.size()){
                odd_even.push_back(nums[i]);
                count++;
                i++;
                }
            }
        }

        int ans = 0;
        ans = max(max(odd.size(), even.size()), max(odd_even.size(), even_odd.size()));

        return ans;
    }

    // f (nums, int i, int length, vector<int>&current){

    //     for (int i = 0; i < current.size(); i++){
    //         if ((current[i] + current[i+1]) % 2 != cuurent[])
    //     }

    //     f (nums, i+1, length, current);
    //     current.push_back(nums[i]);
    //     f(nums, i+1, length, current);
    // }
};