class Solution {
public:
    bool isHappy(int n) {
        set<int>visited;
        int digit, sum;
        
        while (visited.find(n) == visited.end()){
            visited.insert(n);
            
            // squaring
            sum = 0;
            while (n){
                digit = n % 10;
                sum += pow(digit,2);
                n = n/10;
            }
            n = sum;

            if (n == 1)
              return true;
        }
        return false;
        
        
    }
};