class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int current_sum = 0;
        int max_len = 0;
        map<int,int>m;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                nums[i] = -1;
            }
        }

        // now becomes an imp question

        for (int i = 0; i < nums.size(); i++){
            current_sum += nums[i];

            if (current_sum == 0){
                max_len = i + 1;
            }

            if (m.find(current_sum) != m.end()){
                max_len = max(max_len, i - (m[current_sum] + 1) + 1);
            } else {
                m[current_sum] = i;
            }
        }

        return max_len;

    }
};