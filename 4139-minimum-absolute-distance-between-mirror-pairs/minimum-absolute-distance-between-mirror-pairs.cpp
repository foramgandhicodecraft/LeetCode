class Solution {
public:
    int reverse(int num){
        int rev_num = 0;
        while (num % 10 == 0){
            num = num/10;
        }
        if (num == 0){
            return 0;
        }
        while (num != 0){
            rev_num = rev_num*10 + num%10;
            num = num/10;
        }

        return rev_num;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int current;
        map<int, vector<int>>m;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++){
            m[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; i++){
            current = reverse(nums[i]);
            if (m.find(current) != m.end()){
                auto &vec = m[current];
                auto it = upper_bound(vec.begin(), vec.end(), i);
                if (it != vec.end()){
                    ans = min(ans, *it-i);
                }
            }
        }

        if (ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};