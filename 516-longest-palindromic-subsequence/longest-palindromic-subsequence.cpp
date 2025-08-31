class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // return f(s, t, n-1, n-1, dp);

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }

    // int f(string s, string t, int i, int j, vector<vector<int>>dp){
    //     if (i < 0 || j < 0) return 0;

    //     if (dp[i][j] != -1)  return dp[i][j];

    //     if (s[i] == t[j]) return dp[i][j] = 1 + f(s, t, i-1, j-1, dp);

    //     else{
    //         return dp[i][j] = max(f(s, t, i-1, j, dp), f(s,t, i, j-1,dp));
    //     }

        
    // }
};