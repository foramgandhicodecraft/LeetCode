class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        for (auto& word:strs){
            string sortedString = word;
            sort(sortedString.begin(), sortedString.end());

            m[sortedString].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& element:m){
            result.push_back(element.second);
        }

        return result;
    }
};