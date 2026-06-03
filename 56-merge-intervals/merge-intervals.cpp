class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;

        for (int i = 0; i < n; i++){
            if (ans.size() == 0 || ans[ans.size()-1].back() < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else {
                ans[ans.size()-1].back() = max(ans[ans.size()-1].back(), intervals[i][1]);
            }
        }

        return ans;
    }
};