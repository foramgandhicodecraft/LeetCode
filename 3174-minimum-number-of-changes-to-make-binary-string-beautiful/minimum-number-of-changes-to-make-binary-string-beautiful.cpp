class Solution {
public:
    int minChanges(string s) {

        int changes = 0;

        for (int i = 0; i+1 < s.size(); i = i+2){
            if (s[i] != s[i+1]){
                changes++;
            }
        }

        return changes;
    }
};