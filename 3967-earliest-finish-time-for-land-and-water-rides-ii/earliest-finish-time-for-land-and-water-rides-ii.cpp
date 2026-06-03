class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int water_size = waterStartTime.size();
        int land_size = landStartTime.size();
        vector<vector<int>>water(water_size, vector<int>(2));
        int ans = INT_MAX;

        for (int i = 0; i < water_size; i++){
            water[i][0] = waterStartTime[i];
            water[i][1] = waterDuration[i];
        }
        sort(water.begin(), water.end());

        // for the rides which start before land time
        vector<int>prefixDuration(water_size);
        prefixDuration[0] = water[0][1];
        for (int i = 1; i < water.size(); i++){
            prefixDuration[i] = min(prefixDuration[i-1], water[i][1]);
        }

        // for the rides which start after land rides get over
        vector<int>suffixDuration(water_size);
        suffixDuration[water_size-1] = water[water_size-1][0] + water[water_size-1][1];
        for (int i = water_size-2; i >= 0; i--){
            suffixDuration[i] = min(suffixDuration[i+1], water[i][0] + water[i][1]);
        }

        for (int i = 0; i < land_size; i++){
            int land_time = landStartTime[i] + landDuration[i];
            int left = 0;
            int right = water_size-1;
            int idx = water_size;
            while (left <= right) {
                int mid = left + (right-left) / 2;
                if (water[mid][0] > land_time){
                    idx = mid;
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
            // idx will be mid
            int num1 = INT_MAX, num2 = INT_MAX;
            if (idx > 0){
                num1 = land_time+prefixDuration[idx-1];
            } 
            if (idx < water_size){
                num2 = suffixDuration[idx];
            }

            ans = min(ans, min(num1, num2));
        }

        vector<vector<int>>land(land_size, vector<int>(2));
        for (int i = 0; i < land_size; i++){
            land[i][0] = landStartTime[i];
            land[i][1] = landDuration[i];
        }

        sort(land.begin(), land.end());

        vector<int>prefix(land_size);
        vector<int>suffix(land_size);

        prefix[0] = land[0][1];

        for (int i = 1; i < land_size; i++){
            prefix[i] = min(prefix[i-1], land[i][1]);
        }

        suffix[land_size-1] = land[land_size-1][0] + land[land_size-1][1];
        for (int i = land_size-2; i >= 0; i--){
            suffix[i] = min(suffix[i+1], land[i][0] + land[i][1]);
        }

        for (int i = 0; i < water_size; i++){
            int water_time = waterStartTime[i] + waterDuration[i];
            int left = 0;
            int right = land_size - 1;
            int idx = land_size;
            while (left <= right){
                int mid = left + (right-left)/2;
                if (land[mid][0] > water_time){
                    idx = mid;
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }

            int num1 = INT_MAX, num2 = INT_MAX;

            if (idx > 0){
                num1 = water_time + prefix[idx-1];
            }
            if (idx < land_size) {
                num2 = suffix[idx];
            }

            ans = min(ans, min(num1, num2));
        }

        return ans;
    }
};