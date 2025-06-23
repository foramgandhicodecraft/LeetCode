class Solution {
public:
    int myAtoi(string s) {

        int num = 0;
        int sign;
        int i = 0;

        while (i < s.size() && s[i] == ' ') i++; // skip the leading white spaces

        if (s[i] == '-'){
            sign = -1;
            i++; // increment i after checking sign
        }
        else if (s[i] == '+'){
            sign = 1;
            i++;
        }
        else sign = 1;
        
        while (i < s.size()){
            if (s[i] >= '0' && s[i] <= '9'){
                if (num > INT_MAX / 10 ||  
    (num == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
    return sign == 1 ? INT_MAX : INT_MIN;
}

                num = num*10 + (s[i] - '0');
                i++;
            } else{
                break;
            }
        }

        

        return num * sign;
    }
};