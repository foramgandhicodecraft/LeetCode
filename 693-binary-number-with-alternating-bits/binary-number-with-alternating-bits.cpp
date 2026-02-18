class Solution {
public:
    bool hasAlternatingBits(int n) {
        int num = n;
        string binary;
        while (n >= 1){
            binary += (n%2) + '0';
            n = n/2;
        }
        // if (num%2 == 0){
        //     binary += '0';
        // }
        // else{
        //     binary += '1';
        // }
        //cout<<binary;

        int i = 0;
        int j = 1;
        while (j < binary.size()){
            if (binary[i] == binary[j]){
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
};