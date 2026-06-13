class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (auto word:words){
            int current_sum = 0;
            for (int i = 0; i < word.size(); i++){
                current_sum += weights[word[i] - 'a'];
            }
            current_sum = current_sum%26;
            char current = 'z' - current_sum;
            ans += current;
        }

        return ans;
    }
};