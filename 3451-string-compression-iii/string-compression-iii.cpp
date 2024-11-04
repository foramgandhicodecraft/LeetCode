class Solution {
public:
    string compressedString(string word) {
        string comp;
        int length;
        int count;

        for (int i=0; i < word.size();){
            int j = i+1;
            while (j < word.size() && word[i] == word[j]){
                j++;
            }

            count = j-i;

            while (count > 0){
                length = min(9, count);
                comp += to_string(length) + word[i];
                count -=  length;
            }

            i = j;  
        }

        return comp;
    }
};