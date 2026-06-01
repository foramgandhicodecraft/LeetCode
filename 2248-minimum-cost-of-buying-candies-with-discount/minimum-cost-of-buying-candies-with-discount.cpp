class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        int level = 1;
        int amount = 0;

        for (int candy:cost){
            if (level%3 != 0){
                amount += candy;
            }
            level++;
        }

        return amount;
    }
};