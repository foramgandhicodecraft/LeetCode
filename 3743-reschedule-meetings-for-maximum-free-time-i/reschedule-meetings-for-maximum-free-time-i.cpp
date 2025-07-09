class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = eventTime;
        vector<int>gaps(1, startTime[0]); // first gap

        for (int i = 1; i < endTime.size() ; i++){
            gaps.push_back(startTime[i] - endTime[i-1]);
        }

        if (eventTime != endTime.back()){
             gaps.push_back(eventTime - endTime.back());
        }

       
        int max_sum = 0;
        int currentSum = 0;

        for (int i = 0; i < gaps.size(); i++){
            //currentSum += ((i >= k+1) ? gaps[i] - gaps[i-(k+1)]:gaps[i]);
            currentSum += gaps[i] - ((i >= k+1) ? gaps[i-(k+1)]:0);
            max_sum = max(max_sum, currentSum);
        }

        return max_sum;
    }
};