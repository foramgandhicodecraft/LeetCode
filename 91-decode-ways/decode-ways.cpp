class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size(), -1);
        return ways(0,s,dp);
    }

private:
    int ways(int i, string s, vector<int>&dp){

        if (i >= s.size())
          return 1;

        if (s[i] == '0')
         return 0; //invalid decoding

        if(dp[i] != -1)
          return dp[i];


        int result = ways(i+1, s, dp);

        if (i+1 < s.size()){
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            
            if (num >= 10 && num <= 26){
                result += ways(i+2, s, dp);
            }
        }

        return dp[i] = result;
    }
};