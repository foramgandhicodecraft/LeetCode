class Solution {
public:
    int dp[501][501][3];

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        for (int i = 0; i < 501; i++){
            for (int j = 0; j < 501; j++){
                for (int k = 0; k < 3; k++){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins, 0,0,2,m,n);
    }

    int solve (vector<vector<int>>&coins, int i, int j, int neu, int m, int n){
        if (i == m-1 && j == n-1){
            if (coins[i][j] < 0 and neu > 0){
                return 0;
            }
            return coins[i][j]; // if no neutralisation power, return the value whether positive or negative
        }

        if (i >= m || j >= n){
            return INT_MIN;
        }

        if (dp[i][j][neu] != INT_MIN){
            return dp[i][j][neu];
        }

        int take = coins[i][j] + max(solve(coins,i+1,j,neu, m, n), solve(coins,i,j+1,neu,m,n));

        int skip = INT_MIN;
        if (coins[i][j] < 0 && neu > 0){
            int skipDown = solve(coins, i+1, j, neu-1, m ,n);
            int skipRight = solve(coins, i, j+1, neu-1, m, n);

            skip = max(skipDown, skipRight);
        }

        return dp[i][j][neu] = max(take, skip);


    }
};