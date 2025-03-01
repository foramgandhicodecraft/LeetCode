class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                nums[i] = nums[i+1]*2;
                nums[i+1] = 0;
            }
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                ans.push_back(nums[i]);
                j++;
            }
        }
        while(j < nums.size()){
            ans.push_back(0);
            j++;
        }
        return ans;
    }
};