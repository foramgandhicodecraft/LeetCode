class Solution {
public:
    string addStrings(string num1, string num2) {
        // long long a= 0,b = 0;
        // for (int i = 0; i < num1.size(); i++){
        //     long x = num1[i] - '0';
        //     a = a*10 + x;
        // }
        //  for (int i = 0; i < num2.size(); i++){
        //     long x = num2[i] - '0';
        //     b = b*10 + x;
        // }

        // long long sum = a+b;
        // string ans = "";
        // if (sum == 0)
        //   return "0";

        // while (sum > 0){
        //     int y = sum%10;
        //     char lol = y+'0';
        //     sum /= 10;
        //     ans += lol;
        // }

        // reverse(ans.begin(), ans.end());

        // return ans;

        int carry = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        int a,b;
        string ans;
        while (i >= 0 || j >= 0){
            if (i>=0) a = num1[i] - '0';
            else  a = 0;
            if (j>=0) b = num2[j] - '0';
            else  b = 0;
            int sum = a+b+carry;
           
            carry = sum/10;

            ans += sum%10 + '0';
            i--;
            j--;
        }

        if (carry)
          ans += carry + '0';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};