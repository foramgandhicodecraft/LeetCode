class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """

        min_del = 0
        count_b = 0

        for char in s:
            if char == 'a':
                min_del = min(min_del + 1, count_b)
            else:
                count_b = count_b + 1

            min_del = min(min_del, count_b)

        return min_del
        