class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            vector<int>current;
            int num = nums[i];
            while (num != 0){
                current.push_back(num%10);
                num = num/10;
            }
            reverse(current.begin(), current.end());
            ans.insert(ans.end(), current.begin(), current.end());
        }

        return ans;
    }
};