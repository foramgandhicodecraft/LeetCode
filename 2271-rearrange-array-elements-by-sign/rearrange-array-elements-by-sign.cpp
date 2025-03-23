class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0)
               positive.push_back(nums[i]);
            else
               negative.push_back(nums[i]);
        }
        int j = 0, k = 0;

        for (int i = 0; i < nums.size(); i++){
            if(i % 2){
                nums[i] = negative[k++];
            }else{
                nums[i] = positive[j++];
            }
        }

        return nums;
    }
};