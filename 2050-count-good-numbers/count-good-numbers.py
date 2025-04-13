class Solution(object):
    def countGoodNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """

        MOD = 10**9 + 7

        def pow(x, n):
            result = 1
            while n>0:
                if n%2:
                    result = (result*x) % MOD
                n = n // 2
                x = (x*x) % MOD
            return result

        even = (n+1) // 2
        odd = n//2

        return (pow(5, even) * pow(4, odd)) % MOD


        