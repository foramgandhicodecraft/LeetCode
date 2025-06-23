class Solution {
public:
    string countAndSay(int n) {
        string ans="";

        if (n == 0)
          return ans;

        if (n == 1)  return "1";

        ans += "1";
        f(n-1, ans);
        return ans;
    }

private:
    void f (int n, string& ans){
        if (n == 0) return;
        string temp;
        int i = 0;

        while (i < ans.size()){
            int j = i;
            int count = 0;
            while (j < ans.size() && ans[j] == ans[i]){
                count++;
                j++;
            }
            temp += to_string(count) + ans[i];
            i = j;
        }
        ans = temp;

        f(n-1, ans);
    }
};