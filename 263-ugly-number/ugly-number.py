class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """

        if (n == 0 or n < 0):
            return False


        for factor in [2, 3, 5]:
            while (n % factor == 0):
                n = n / factor

        if (n == 1):
            return True

        else:
            return False
        