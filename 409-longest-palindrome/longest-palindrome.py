class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        letters = defaultdict(int) #for setting initial count of all letters to 0
        ans = 0

        for i in s:
            letters[i] +=  1
            if letters[i] % 2 == 0:
                ans += 2
        
        for letter in letters:
            if letters[letter] % 2 != 0:
                ans += 1
                break

        return ans