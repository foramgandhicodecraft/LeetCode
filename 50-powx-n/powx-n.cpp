class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if (nn < 0){
            nn = nn * (-1);
        }
        double ans = 1;

        while (nn) {
            if (nn % 2 == 0){
                x = x*x;
                nn = nn/2;
            }
            else {
                nn = nn-1;
                ans = ans*x;
            }
        } 

        if (n < 0){
            return 1/ans;
        }
        return ans;
    }
};