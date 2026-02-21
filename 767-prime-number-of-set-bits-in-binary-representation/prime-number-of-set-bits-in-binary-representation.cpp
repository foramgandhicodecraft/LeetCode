class Solution {
public:
    bool isPrime (int num){
            if (num <= 1){
                return false;
            }
            for (int i = 2; i <= num/2; i++){
                if (num % i == 0){
                    return false;
                }
            }
            return true;
    }

    int countPrimeSetBits(int left, int right) {
        //int set_count = 0;
        int ans = 0;
        
        for (int i = left; i <= right; i++){
            int set_count = __builtin_popcount(i);
            if (isPrime(set_count)){
                ans++;
            }
        }

        return ans;
    }
};