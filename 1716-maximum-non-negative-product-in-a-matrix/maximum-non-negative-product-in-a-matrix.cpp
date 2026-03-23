class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long>> max_dp(m, vector<long long>(n));
        vector<vector<long long>> min_dp(m, vector<long long>(n));
        
        return getmax(grid, max_dp, min_dp, m, n);
    }

    int getmax(vector<vector<int>>& grid,
               vector<vector<long long>>& max_dp,
               vector<vector<long long>>& min_dp,
               int m, int n) {

        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            max_dp[0][j] = max(
                max_dp[0][j-1] * grid[0][j],
                min_dp[0][j-1] * grid[0][j]
            );
            min_dp[0][j] = min(
                max_dp[0][j-1] * grid[0][j],
                min_dp[0][j-1] * grid[0][j]
            );
        }

        // first column
        for (int i = 1; i < m; i++) {
            max_dp[i][0] = max(
                max_dp[i-1][0] * grid[i][0],
                min_dp[i-1][0] * grid[i][0]
            );
            min_dp[i][0] = min(
                max_dp[i-1][0] * grid[i][0],
                min_dp[i-1][0] * grid[i][0]
            );
        }

        // rest
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];

                long long a = max_dp[i-1][j] * val;
                long long b = min_dp[i-1][j] * val;
                long long c = max_dp[i][j-1] * val;
                long long d = min_dp[i][j-1] * val;

                max_dp[i][j] = max({a, b, c, d});
                min_dp[i][j] = min({a, b, c, d});
            }
        }

        long long res = max_dp[m-1][n-1];

        if (res < 0) return -1;

        return res % 1000000007;
    }
};