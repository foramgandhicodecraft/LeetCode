class Solution {
public:
    bool checkOnesSegment(string s) {

        bool occur = false;
        int i = 0;

        while (i < s.size()){
            if (s[i] == '1' && occur == true){
                return false;
            }
            else if (s[i] == '1' && occur == false){
                while (i < s.size() && s[i] == '1'){
                    i++;
                }
                occur = true;
            }
            else{
                i++;
            }
        }

        return true;
    }
};