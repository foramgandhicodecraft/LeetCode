class Solution {
public:
    string makeFancyString(string s) {
        string ans;

        int i = 0;
        int j = i;

        while (i < s.size()){
            
            int count = 0;

            while (s[j] == s[i]){
                count++;
                j++;

                if (count < 3){
                    ans += s[i];
                }
            }
            i= j;
        }

        return ans;
    }
};