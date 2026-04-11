class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // traverse and store indices if size == 3 calculate distance for size greater than 3 increase one to move to the index
        // 2*(c-a)

        int n = nums.size();
        map<int, vector<int>>m;
        int n1;
        int n2;
        int ans = INT_MAX;
        int num;
        bool direction = false;

        for (int i = 0; i < n; i++){
            m[nums[i]].push_back(i);
            if (m[nums[i]].size() == 3){
                direction = true;
                n1 = m[nums[i]][0];
                n2 = i;
                num = 2*(n2 - n1);
                ans = min(ans, num);
            }
            else if (m[nums[i]].size() > 3){
                direction = true;
                m[nums[i]].erase(m[nums[i]].begin());
                n1 = m[nums[i]][0];
                n2 = i;
                num = 2*(n2 - n1);
                ans = min(ans, num);
            }
        }

        if (direction){
            return ans;
        }

        return -1;
    }
};