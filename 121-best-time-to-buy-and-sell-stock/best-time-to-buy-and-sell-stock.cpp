class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = INT_MAX;

        for (int num: prices){
            min_buy = min(min_buy, num);
            int profit = num - min_buy;
            max_profit = max(max_profit, profit);
        }

        return max_profit;
    }
};