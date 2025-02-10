class Solution {
public:
    string clearDigits(string s) {
        int j;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                s[i] = '|';
                j = i - 1;
                while (j >= 0){
                    if (s[j] >= 'a' && s[j] <= 'z'){
                        s[j] = '|';
                        break;
                    }
                    j--;
                }
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != '|'){
                ans += s[i];
            }
        }

        return ans;
    }
};