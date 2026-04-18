class Solution {
public:
    int mirrorDistance(int n) {
        int num = n;
        int rev_num = 0;
        while (num != 0){
            rev_num = rev_num*10 + num%10;
            num = num/10;
        }

        return abs(n-rev_num);
    }
};