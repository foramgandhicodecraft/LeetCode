class Solution {
public:
    double myPow(double x, int n) {
        double nn = n;
        if (nn < 0){
            nn = nn * (-1);
        }
        double ans = pow(x,nn);

        if (n < 0){
            return 1/ans;
        }

        return ans;
    }
};