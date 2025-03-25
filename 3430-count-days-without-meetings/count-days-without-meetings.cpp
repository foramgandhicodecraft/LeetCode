class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int sum = 0;
        // first perform the merge interval question
        vector<vector<int>> merge_interval;
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++){
            if (merge_interval.empty() || merge_interval.back()[1] < meetings[i][0]){
                merge_interval.push_back(meetings[i]);
            }
            else{
                merge_interval.back()[1] = max(merge_interval.back()[1], meetings[i][1]);
            }
        }

        for (int i = 0; i < merge_interval.size(); i++){
            sum += merge_interval[i][1] - merge_interval[i][0] + 1;
        }

        return days - sum;
    }
};