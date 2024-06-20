class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        
        num_str = str(x)
        rev_num_str = num_str[::-1]

        if (num_str == rev_num_str):
            return True
        else:
            return False