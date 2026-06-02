class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_time = INT_MAX;
        int land = landStartTime.size();
        int water = waterStartTime.size();

        for (int i = 0; i < land; i++){
            int current_land = landStartTime[i] + landDuration[i];
            for (int j = 0; j < water; j++){
                if (waterStartTime[j] > current_land) {
                    int total_time = current_land +  waterDuration[j] + (waterStartTime[j] - current_land);
                    min_time = min(min_time, total_time);
                }
                else {
                    int total_time = current_land + waterDuration[j];
                    min_time = min(min_time, total_time);
                }
            }
        }

        for (int i = 0; i < water; i++){
            int current_water = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < land; j++){
                if (landStartTime[j] > current_water) {
                    int total_time = current_water +landDuration[j] + (landStartTime[j] - current_water);
                    min_time = min(min_time, total_time);
                }
                else {
                    int total_time = current_water + landDuration[j];
                    min_time = min(min_time, total_time);
                }
            }
        }

        return min_time;
    }
};