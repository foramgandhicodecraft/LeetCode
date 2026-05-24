class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;

        int i = 0, j = 0;

        while (j < s.size()){
            if (i < g.size() && s[j] >= g[i]){
                count++;
                i++;
            }
            j++;;
        }

        return count;
    }
};