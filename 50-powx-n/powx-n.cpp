class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;

        long long nn = abs((long long)n); 

        while (nn > 0){
            if (nn % 2 == 0){
                x = x*x;
                nn = nn/2;
            }
            else{
                ans = ans * x;
                nn = nn-1;
            }
        }

        if (n < 0){
            ans = 1/ans;
        }

        return ans;
    }
};