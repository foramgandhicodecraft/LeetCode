class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """

        pascal = []

        for row in range(numRows):
            line = []
            res = 1
            for coloumn in range(row+1):
                if (coloumn == 0 or coloumn == row):
                    line.append(1)
                else:
                    res = res*((row-coloumn)+1)
                    res = res//coloumn
                    line.append(res)
            pascal.append(line)
        return pascal
        