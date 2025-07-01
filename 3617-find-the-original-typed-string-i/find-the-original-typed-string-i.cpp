class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1; // count the whole string
        int j = 0;
        int i = 0;
        int current = 0;

        while (i < word.size()){
            if (word[i] == word[j]){
                current++;
            }
            else{
                i = j;
                count += current - 1;
                current = 1;
            }
            j++;
        }

        return count;
    }
};