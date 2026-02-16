class Solution {
public:
    string addBinary(string a, string b) {
        // int p = a.size()-1;
        // int q = b.size()-1;
        // string ans;
        //int carry = 0;

        // while (p>=0 && q>=0){
        //     carry = 0; 
        //     int first = a[p] - '0';
        //     int second = b[q] - '0';
        //     int current = first+second;
        //     carry = current/10;
        //     ans += (current%10) + '0';
        //     p--;
        //     q--;
        // }

        // while (p >= 0){

        // }
        // if (carry){
        //     ans.push_back(carry);
        // }

        // reverse(ans.begin(), ans.end());

        // return ans;

        // 1 + 1 = 0 with carry=1
        // 1 + 0 = 1 with carry=0
        // 0 + 0 = 0
        // int carry = 0;
        // int one_count = 0;
        // int zero_count = 0;

        // while (p >= 0 && q >= 0){
        //     if (a[p] == '1'){
        //         one_count++;
        //     }
        //     else if (a[p] == '0'){
        //         zero_count++;
        //     }
        //     if (b[q] == '1'){
        //         one_count++;
        //     }
        //     else if (b[q] == '0'){
        //         zero_count++;
        //     }

        //     if (one_count == 2){
        //         carry = 1;
        //         ans += '0';
        //     }
        //     else if (one_count == 3){
        //         carry = 1;
        //         ans += '1';
        //     }
        //     else if (one_count == 1){
        //         ans += '1';
        //     }
        //     else if (zero_count == 2){
        //         ans += '0';
        //     }
            
        // }

        int sum = 0;
        int ptr1 = a.size()-1;
        int ptr2 = b.size()-1;
        string ans;
        int carry = 0;

        while (ptr1 >= 0 || ptr2 >= 0 || carry > 0){
            if (ptr1 >= 0){
                sum += a[ptr1] - '0';
                ptr1--;
            }
            if (ptr2 >= 0){
                sum += b[ptr2] - '0';
                ptr2--;
            }

            ans += (sum%2) + '0';
            carry = sum/2;
            sum = carry;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};