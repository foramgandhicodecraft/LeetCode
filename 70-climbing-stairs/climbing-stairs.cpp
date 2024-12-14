class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2){
            return n;
        }

        int i;
        int p1 = 1;
        int p2 = 2;
        int current;

        for (i = 3; i <=n; i++){
            current = p1 + p2;
            p1 = p2;
            p2 = current;
        }

        return current;
    }
};