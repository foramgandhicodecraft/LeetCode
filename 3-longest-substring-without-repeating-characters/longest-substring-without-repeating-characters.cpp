class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();
        set<char>current;
        int ans = 0;

        for (right = 0; right < n; right++){
                while (left <= right && current.find(s[right]) != current.end()){
                    current.erase(s[left]);
                    left++;
                    //ans = max(ans, right-left+1);
                }
                current.insert(s[right]);
                ans = max(ans, right-left+1);
        }

        return ans;
    }
};