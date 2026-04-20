class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int j = n-1;
        int ans = 0;

        // choose from right
        while (j >= 0){
            if (colors[j] != colors[i]){
                ans = max(ans, j-i);
                break;
            }
            else {
                j--;
            }
        }

        // choose from left
        j = n-1;
        while (i < n){
            if (colors[i] != colors[j]){
                ans = max(ans, j-i);
                break;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};