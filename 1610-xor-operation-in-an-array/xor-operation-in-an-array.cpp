class Solution {
public:
    int xorOperation(int n, int start) {
        int current;
        int ans = start;
        
        for (int i = 1; i < n; i++){
            current = start + 2 * i;
            ans = ans^current;
        }

        return ans;


    }
};