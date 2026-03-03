class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1){
            return '0';
        }

        int length = pow(2,n) - 1;

        if (k < ceil(length / 2.0)){
            char c = findKthBit(n-1, k);
            return c;
        }
        else if (k == ceil(length/2.0)){
            return '1';
        }
        else{
            char c = findKthBit(n-1, length-(k-1));
            if (c == '1'){
                return '0';
            } else{
                return '1';
            }
        }

        return '0';
    }
};