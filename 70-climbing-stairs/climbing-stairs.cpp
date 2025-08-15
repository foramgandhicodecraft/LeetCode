class Solution {
public:
    int climbStairs(int n) {
        int p1 = 1;
        int p2 = 2;
        int current;

        if (n <= 2){
            return n;
        }

        for (int i = 3; i <=n; i++){
            current = p1+p2;
            p1=p2;
            p2=current;
        }

        return current;
    }
};