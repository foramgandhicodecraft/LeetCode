class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool even = false;
        bool odd = false;

        if ((s1[0] == s2[2] && s1[2] == s2[0]) || (s1[0] == s2[0] && s1[2] == s2[2])){
            even = true;
        }
        if ((s1[1] == s2[3] && s1[3] == s2[1]) || (s1[1] == s2[1] && s1[3] == s2[3])){
            odd = true;
        }

        if (odd && even){
            return true;
        }
        return false;
        
    }
};