class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==1) return true;
        if (n == 0) return false;
        if (n < 0) return false;
        
        // float value should return 1.00
        // float num = n;

        // while (num){
        //     if (num/2.0 == 1.0){
        //       return true;
        //     }
        //     num = num / 2.0;
        // }

        // return false;

        while (n >= 2){
            if (n%2 != 0) return false;
            n = n / 2;
        }

        return true;
    }
};