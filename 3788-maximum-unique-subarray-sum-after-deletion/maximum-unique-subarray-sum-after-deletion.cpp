class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int left = 0;
        long long sum = 0;
        long long max_sum = INT_MIN;
        bool negative = true;

        for (int num:nums){
            if (num > 0) {
                negative = false;
                break;
            }
        }

        if (negative){
            int max_neg = nums[0];
            for (int num:nums){
                max_neg = max(max_neg, num);
            }

            return max_neg;
        }

        // for (int right = 0; right < nums.size(); right++){

        //     // remove duplicates
        //     while (left < right && s.find(nums[right]) != s.end()){
        //         s.erase(nums[left]);
        //         sum -= nums[left];
        //         left++;
                
        //     }

        //     while (nums[left] < 0 && left < right) left++;

        //     // sum = max(sum+nums[right], (long long)nums[right]);
        //     // s.insert(nums[right]);
        //     //right++;
        //     // max_sum = max(max_sum, sum);
        //     if (nums[right] >= 0){
        //         s.insert(nums[right]);
        //         sum += nums[right];
        //         max_sum = max(max_sum, sum);
        //     } 
        // }

        // return (int)max_sum;

        for (int num:nums){
            if (num >= 0){
                s.insert(num);
            }
            
        }

        for (int num:s){
            sum += (long long) num;
        }

        return (int)sum;
    }
};