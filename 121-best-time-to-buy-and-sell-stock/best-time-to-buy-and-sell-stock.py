class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        min_price = float('inf')
        max_profit = 0
        
        for price in prices:
            #check the min_price
            if (min_price > price):
                min_price = price
            #calculate the cost
            cost = price-min_price
            #find the max_profit
            if (cost > max_profit):
                max_profit = cost
        
        return max_profit

        