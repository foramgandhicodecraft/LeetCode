class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxi = INT_MIN;
        set<char>ss;

        if (s.size() == 0) return 0;
        
        for (int r = 0; r < s.size(); r++){
            
            while (ss.find(s[r]) != ss.end()){
                ss.erase(s[l]);
                l++;
            }

            ss.insert(s[r]);
            maxi = max(maxi, r-l+1);
            
        }

        return maxi;
    }
};