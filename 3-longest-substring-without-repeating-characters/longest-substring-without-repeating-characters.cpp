class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_set<char>track;
        int max_length = 0;
        
        for (right = 0; right < s.size(); right++){
            while (track.find(s[right]) != track.end()){
                track.erase(s[left]);
                left++;
            }
            track.insert(s[right]);
            max_length = max(max_length, right-left+1);
        }
        return max_length;
    }
};