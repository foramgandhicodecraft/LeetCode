class Solution {
public:
    string largestGoodInteger(string num) {

        vector<int>v;
        
        for (int i = 0; i < num.size()-2; i++){
            if ((num[i] == num[i+1]) && (num[i+1] == num[i+2])){
                string ans = num.substr(i, 3);
                v.push_back(stoi(ans));
            }
        }


        if (v.size() != 0){
            sort(v.begin(), v.end());
            int n = v[v.size()-1];
            if (n == 0){
                return "000";
            }
            return to_string(n);
        }

        


        return "";
    }
};