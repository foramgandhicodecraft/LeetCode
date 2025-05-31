class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        palindrome(0,s,ds,ans);
        return ans;
    }

private:
    void palindrome(int partition, string s, vector<string>& ds, vector<vector<string>>& ans){
        if (partition == s.size()){
            ans.push_back(ds);
            return;
        }

        for (int i = partition; i < s.size(); i++){
            if (isPalindrome(s, partition, i)){
                ds.push_back(s.substr(partition, i-partition+1));
                palindrome(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int index, int i){
        while (index < i){
            if (s[index++] != s[i--])
              return false;
        }
        return true;
    }
    
};