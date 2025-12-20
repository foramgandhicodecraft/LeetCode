class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int m = strs[0].size();

        for (int i = 0; i < m; i++){
            vector<char>current;
            for (int k = 0; k < strs.size(); k++){
                current.push_back(strs[k][i]);
            }
            vector<char>temp = current;
            sort(current.begin(), current.end());
            if (current != temp){
                count += 1;
            }
        }

        return count;

    }
};