class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // sort the factories
        // sort the robots
        // traverse robot array and find minimum distance of current robot from factories
        // if factory's limit is complete, remove it from the factory array
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // 0 index to first factory, all robots will go into first factory
        // int robot_ptr = robot[0];
        // int i = 0; // keeping track of robot

        // while (robot _ptr <= factory[0][0]){
        //     i++; // robot repaired
        //     robot_ptr = robot[i];
        //     factory[0][1]--;
        //     if (factory[0][1] == 0){
        //         factory.erase(factory.begin());
        //     }
        // }

        // int distance = 0;

        // //int j = 0;
        // for (int i = 0; i < robot.size(); i++){
        //     factory[0][1]--;
        //     distance += abs(i - factory[0][0]);
        //     if (factory[0][1] == 0){
        //         factory.erase(factory.begin());
        //     }
        // }

        // return distance;

        vector<int>facs;
        for (int i = 0; i < factory.size(); i++){
            for (int j = 0; j < factory[i][1]; j++){
                facs.push_back(factory[i][0]);
            }
        }
        int i = 0; //robot pointer
        int j = 0; // factory pointer
        vector<vector<long long>>dp(robot.size(),vector<long long>(facs.size(), -1));

        return distance(robot, facs, i, j, dp);
    }

    long long distance(vector<int>&robot, vector<int>&facs, int i, int j, vector<vector<long long>>&dp){
        if (i >= robot.size()){
            return 0;
        }
        if (j >= facs.size()){
            return 1e12; // return 10^12 (a sufficient good value) instead of INT_MAX
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        long long take = abs(robot[i] - facs[j]) + distance(robot, facs, i+1, j+1, dp);
        long long skip = distance(robot, facs, i, j+1, dp);

        return dp[i][j] = min(take, skip);
    }
};