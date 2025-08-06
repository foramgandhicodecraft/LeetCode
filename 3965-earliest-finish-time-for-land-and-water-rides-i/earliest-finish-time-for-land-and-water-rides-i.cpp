class Solution {
public:
    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        // int min_add = INT_MAX;
        // int min_land = INT_MAX;
        // int min_water = INT_MAX;
        // int from_land = true;

        // for (int i = 0; i < landStartTime.size(); i++){
        //     min_add = min(min_add, landStartTime[i] + landDuration[i]);
        //     min_land = min(min_land, landDuration[i]);
        // }

        // for (int i = 0; i < waterStartTime.size(); i++){
        //     if (waterStartTime[i] + waterDuration[i] < min_add){
        //         min_add = waterStartTime[i] + waterDuration[i];
        //         from_land = false;
        //     }
        //     min_water = min(min_water, waterDuration[i]);
        // }

        // int ans;

        // if (from_land){
        //     ans = min_add + min_water;
        // } else {
        //     ans = min_add + min_land;
        // }

        // return ans;

        int land = INT_MAX;
        int water = INT_MAX;

        for (int i = 0; i < a.size(); i++){
            land = min(land, a[i] + b[i]);
        }

        for (int i = 0; i < c.size(); i++){
            water = min(water, c[i]+d[i]);
        }


        int land_water = INT_MAX;
        for (int i = 0; i < c.size(); i++){
            land_water = min(land_water, max(land, c[i])+d[i]);
        }

        int water_land = INT_MAX;
        for (int i = 0; i < a.size(); i++){
            water_land = min(water_land, max(water, a[i])+b[i]);
        }

        int ans = min(land_water, water_land);

        return ans;
        
    }
};