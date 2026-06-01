class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string ans;
        string current;

        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' '){
                current += s[i];
            }
            else{
                if (!(current.size() == 0)) {
                    st.push(current);
                    current = "";
                }
            }
        }

        if (!current.empty()){
            st.push(current);
        }

        while (!st.empty()){
            string word = st.top();
            ans += word;
            st.pop();
            ans += " ";
        }
        ans.erase(ans.begin()+(ans.size()-1));

        return ans;
    }
};