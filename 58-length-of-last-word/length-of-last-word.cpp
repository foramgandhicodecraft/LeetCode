class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int ptr = s.size()-1;

        while (ptr >= 0 && s[ptr] == ' '){
            ptr--;
        }

        while (ptr >= 0 &&s[ptr] != ' '){
            count++;
            ptr--;
        }

        return count;
    }
};