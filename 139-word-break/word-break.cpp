class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // converting wordDict to a set
        set<string>words(wordDict.begin(), wordDict.end());
        vector<int>dp(s.size(), -1); // dp will store whether it from each indexx taken as the start index, the word can be segmneted or not
        return f(s, words, 0, dp);

    }

    bool f (string s, set<string>&words, int start, vector<int>&dp){
        if (start == s.size())
          return true;

        if (dp[start] != -1) return dp[start];

        for (int end = start; end < s.size(); end++){
            string word = s.substr(start, end-start+1);
            if (words.count(word)){
               if (f(s, words, end+1, dp)){
                    return dp[start] = 1;
                }
            }
        }

        return dp[start] = 0;
    }
};