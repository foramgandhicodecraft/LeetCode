class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for (int i = num1; i <= num2; i++){
            vector<int>current;
            int num = i;
            while(num){
                current.push_back(num%10);
                num = num/10;
            }
            for (int j = 1; j < current.size()-1; j++){
                if ((current[j] > current[j+1] && current[j] > current[j-1]) || (current[j] < current[j+1] && current[j] < current[j-1]) ){
                    count++;
                }
            }
        }

        return count;
    }
};