class Solution {
public:
    int longestBalanced(string s) {
        if (s.size() == 0){
            return 0;
        }
        if (s.size() == 1){
            return 1;
        }
        
        int ans = INT_MIN;
        for (int i = 0; i < s.size()-1; i++){
            map<char, int>count;
            count[s[i]] += 1;
            for (int j = i+1; j < s.size(); j++){
                count[s[j]] += 1;
                int check = count.begin()->second;
                int accept = 0;
                for (auto key:count){
                    if (check == key.second){
                        accept++;
                    }
                }
                if (accept == count.size()){
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};