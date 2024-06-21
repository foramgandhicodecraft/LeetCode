class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """

        x = len(digits)
        
        for i in range (x-1,-1,-1):

            if (digits[i]!=9):
                digits[i]= digits[i] + 1
                return digits

            else:
                digits[i] = 0

        digits = [1]+digits


        return digits
