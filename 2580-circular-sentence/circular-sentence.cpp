class Solution {
public:
    bool isCircularSentence(string sentence) {
        string check;

        check += sentence[0];
        for (int i = 0; i < sentence.size(); i++){
            if (sentence[i] == ' '){
                check += sentence[i-1];
                check += sentence[i+1];
            }
        }
        check += sentence[sentence.size()-1];

        //check circular
        for (int i = 1; i < check.size()-2; i += 2){
            if (check[i] != check[i+1]){
                return false;
            }
        }

        if (check[0] != check[check.size()-1]){
                return false;
            }

        return true;

    }
};