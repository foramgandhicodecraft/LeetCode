class Solution {
public:
    int reverseBits(int n) {

        // int num = 0;
        // int reversed_num = 0;
        // int ans = 0;

        // while (n != 0){
        //     num = (num*10) + (n%2);
        //     n = n/2;
        // }

        // while (num != 0){
        //     reversed_num = (reversed_num*10) + (num%10);
        //     num = num/10;
        // }

        // int power = 0;
        // while (reversed_num != 0){
        //     ans += pow(2, power) * (reversed_num%10);
        //     reversed_num =  reversed_num/10;
        //     power++;
        // }

        // return ans;

        int result = 0;
        for (int i = 0; i < 32; i++){
            int curr = n&1;
            result = (result<<1) | curr;
            n = n>>1;
        }

        return result;

    }
};