class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        if (nums.size() == 1)
          return nums[0];

        double max_sum = -INFINITY;
        double sum;

        // compute sum of first k elements
        for (int i = 0; i < k; i++){
            sum += nums[i];
        }
        max_sum = sum;
        
        // add element from back and remove element from front
        for (int i = k; i < nums.size(); i++){
            sum += nums[i];
            sum -= nums[i-k];
            max_sum = max(max_sum,sum);
        }
        return max_sum/k;
    }
};