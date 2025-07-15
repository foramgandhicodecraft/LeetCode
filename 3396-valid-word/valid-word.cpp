class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3){
            return false;
        }

        int vowel = 0;
        int conso = 0;
        int digit = 0;

        for (char ch:word){
            if (check_vowel(ch)){
                vowel++;
            }
            else if (check_conso(ch)){
                conso++;
            }
            else if (check_digit(ch)){
                digit++;
            }
            else{
                return false;
            }
        }

        if (vowel >= 1 && conso >= 1){
            return true;
        }

        return false;
    }

    bool check_vowel(char ch){
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch  == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch  == 'O' || ch == 'U')
          return true;
        return false;
    }

    bool check_conso(char ch){
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
         return true;

        return false;
    }

    bool check_digit(char ch){
        if (ch >= '0' && ch <= '9') 
          return true;

        return false;
    }
};