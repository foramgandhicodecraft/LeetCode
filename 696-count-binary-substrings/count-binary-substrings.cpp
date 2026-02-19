class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero = 0;
        int one = 0;
        int sub = 0;
        int i = 0;

        while (i < s.size()){
            if (s[i] == '0'){
                while (s[i] == '0'){
                    zero++;
                    if (one >= zero){
                       sub++;
                       //sub += one/2;
                    }
                    i++;
                }
                one = 0;
            }
            else{
                while (s[i] == '1'){
                    one++;
                    if (one <= zero){
                       sub++;
                       //sub += one/2;
                    }
                    i++;
                }
                zero = 0;
            }
        }

        return sub;
    }
};