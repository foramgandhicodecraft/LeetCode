class Solution {
public:
    bool judgeCircle(string moves) {
        int up_down = 0;
        int left_right = 0;

        for (char c:moves){
            if (c == 'U'){
                up_down++;
            }
            else if (c == 'D'){
                up_down--;
            }
            else if (c == 'R'){
                left_right++;
            }
            else{
                left_right--;
            }
        }

        if (up_down == 0 && left_right == 0){
            return true;
        }

        return false;
    }
};