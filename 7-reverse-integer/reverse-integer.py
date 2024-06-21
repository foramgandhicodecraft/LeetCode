class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """


        if x == 0:
            return 0
        
        negative = x < 0
        x = abs(x)
        rev_digit = 0

        while x != 0:
            digit = x % 10
            x = x // 10
            rev_digit = rev_digit * 10 + digit
        
        # Handle negative case
        if negative:
            rev_digit = -rev_digit
        
        # Check for overflow (outside the 32-bit signed integer range)
        if rev_digit < -(2**31) or rev_digit > (2**31 - 1):
            return 0
        
        return rev_digit
