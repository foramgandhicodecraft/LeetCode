class Solution(object):
    def maximumCandies(self, candies, k):
        """
        :type candies: List[int]
        :type k: int
        :rtype: int
        """

        total_candies = sum(candies)
        if total_candies < k:
            return 0  # Not enough candies to give at least one to each child
        
        left, right = 1, total_candies // k
        ans = 0

        while left <= right:
            mid = (left + right) // 2
            piles = sum(c // mid for c in candies)  # Count how many children can get mid candies each
            
            if piles >= k:  # If we can distribute to at least k children
                ans = mid
                left = mid + 1  # Try for more candies per child
            else:
                right = mid - 1  # Reduce the candy amount

        return ans

        