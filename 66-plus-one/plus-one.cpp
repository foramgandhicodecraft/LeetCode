class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // unsigned long long num = 0;

        // for (int i:digits){
        //     num = num*10 + i;
        // }

        // num += 1;

        // vector<int>ans;
        // while (num!=0){
        //     ans.push_back(num%10);
        //     num = num/10;
        // }

        // reverse(ans.begin(), ans.end());

        // return ans;

        int i = digits.size()-1;
        vector<int>ans;

        if (digits[i] != 9){
                digits[i] += 1;
                return digits;
        }
        else{
            int count = 0;
            // bool flag;
            while(i >= 0 && digits[i] == 9){
                count++;
                i--;
            }
            // if (count){
            //     flag = true;
            // }
            while (count--){
                ans.push_back(0);
            }
            
                if (i >= 0){
                    digits[i] += 1;
                }
                else{
                    ans.push_back(1);
                }
            

            while (i >= 0){
                ans.push_back(digits[i]);
                i--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};