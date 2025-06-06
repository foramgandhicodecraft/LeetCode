class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, greed = 0;

        while (i < s.size() && j < g.size()){
            if (s[i] >= g[j]){
                greed++;
                j++;
            }
            i++;
        }

        return greed;
    }
};