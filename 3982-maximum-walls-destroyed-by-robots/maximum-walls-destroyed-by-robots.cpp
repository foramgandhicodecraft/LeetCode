class Solution {
public:

    int firstGreaterEqual(vector<int>& walls, int target) {
    int low = 0, high = walls.size() - 1;
    int ans = walls.size(); 

    while (low <= high) {
        int mid = (low + high) / 2;

        if (walls[mid] >= target) {
            ans = mid;         
            high = mid - 1;     
        } else {
            low = mid + 1;      
        }
    }
    return ans;
}

int firstGreater(vector<int>& walls, int target) {
    int low = 0, high = walls.size() - 1;
    int ans = walls.size();

    while (low <= high) {
        int mid = (low + high) / 2;

        if (walls[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int countWalls(vector<int>& walls, int first, int last) {
    int leftIndex = firstGreaterEqual(walls, first);
    int rightIndex = firstGreater(walls, last);

    return rightIndex - leftIndex;
}

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> roboDist(n);

        for (int i = 0; i < n; i++){
            roboDist[i].first = robots[i];
            roboDist[i].second = distance[i];
        }

        sort (roboDist.begin(), roboDist.end());
        sort (walls.begin(), walls.end());

        vector<pair<int, int>> range(n);

        for (int i = 0; i < n; i++){
            int pos = roboDist[i].first;
            int dis = roboDist[i].second;

            int rightLimit = (i == n-1) ? 1e9: roboDist[i+1].first - 1;
            int leftLimit = (i == 0)? 1: roboDist[i-1].first + 1;

            int L = max(leftLimit, pos-dis);
            int R = min(rightLimit, pos+dis);

            range[i] = {L, R};
        }

        vector<vector<int>>dp(n, vector<int>(2,-1));

        return solve(walls, roboDist, range, 0, 0, dp);
    }

    int solve(vector<int>&walls, vector<pair<int, int>>&roboDist, vector<pair<int, int>>&range, int i, int dir, vector<vector<int>>&dp){

        if (i == roboDist.size()){
            return 0;
        }

        if (dp[i][dir] != -1){
            return dp[i][dir];
        }

        int leftStart = range[i].first;

        if (dir == 1 && i > 0){ // prev robot fired bullet to right
           leftStart = max(leftStart, range[i-1].second+1);
        }

        int leftTake = countWalls(walls, leftStart, roboDist[i].first) + solve(walls,roboDist,range,i+1,0,dp);

        int rightTake = countWalls(walls, roboDist[i].first, range[i].second) + solve(walls,roboDist,range,i+1,1,dp);

        return dp[i][dir] = max(leftTake, rightTake);

        
    }
};