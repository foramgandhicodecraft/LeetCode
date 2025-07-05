class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int>freq;
        int ans = -1;

        for (int num:arr){
            freq[num]++;
        }

        for (auto itr:freq){
            if (itr.first == itr.second){
                int current = itr.first;
                ans = max(ans, current);
            }
        }

        return ans;
    }
};