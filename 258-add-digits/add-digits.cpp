class Solution {
public:
    int addDigits(int num) {
    int sum = num;
    int sum1;

    while (sum/10 != 0){
        while (num != 0){
            sum1 += num%10;
            num = num/10;
        }
        num = sum1;
        sum = sum1;
        sum1 = 0;
    }

    return sum;
    }
};