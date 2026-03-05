class Solution {
public:
    int minOperations(string s) {
        int change = 0;
        int count_1 = 0;
        int count_0 = 0;

        // starts with 1
        for (int i = 0; i < s.size(); i++){
            if (i%2 == 0 && s[i] != '1'){
                count_1++;
            }
            else if (i%2 != 0 && s[i] != '0'){
                count_1++;
            }
        }

        // starts with 0
        for (int i = 0; i < s.size(); i++){
            if (i%2 == 0 && s[i] != '0'){
                count_0++;
            }
            else if (i%2 != 0 && s[i] != '1'){
                count_0++;
            }
        }

        change = min(count_1, count_0);

        return change;
    }
};