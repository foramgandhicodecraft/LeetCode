class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int>m;
        vector<int>ans;

        for (int num:nums){
            m[num]++;
        }

        for(int num:nums){
            if (m[num] == 1){
                if (m.find(num-1) == m.end() && m.find(num+1) == m.end()){
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};