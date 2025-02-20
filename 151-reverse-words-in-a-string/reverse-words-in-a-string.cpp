class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string current;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ')
                current.push_back(s[i]);
            else{
                if (!current.empty()){
                 st.push(current);
                 current = "";
                }
            }   
        }
        if (!current.empty()){
            st.push(current);
        }
        string ans;
        string word;
        while (!st.empty()){
            word = st.top();
            st.pop();
            ans += word;
            ans += " ";
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};