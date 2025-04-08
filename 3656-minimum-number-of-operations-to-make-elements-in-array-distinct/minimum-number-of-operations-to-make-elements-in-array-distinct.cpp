class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>m;
        int count_distinct = 0;
        int operations = 0;
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }
        while (nums.size() > 0){
            for (auto key:m){
                if (key.second == 1){
                    count_distinct++;
                }
            }
            if (count_distinct == nums.size()){
                return operations;
            }
            else{
                
                if (nums.size() > 0){
                    m[nums[0]] -= 1;
                   nums.erase(nums.begin());
                }
                if (nums.size() > 0){
                    m[nums[0]] -= 1;
                   nums.erase(nums.begin());
                }
                if (nums.size() > 0){
                    m[nums[0]] -= 1;
                   nums.erase(nums.begin());
                }
                operations++;
                count_distinct = 0;
            }
        }

        return operations;
    }
};