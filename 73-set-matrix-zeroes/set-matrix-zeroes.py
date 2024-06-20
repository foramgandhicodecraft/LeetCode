class Solution(object):
    def setZeroes(self, matrix):
        n = len(matrix)
        m = len(matrix[0])
        rows = [0]*n
        col = [0]*m

        for i in range(n):
            for j in range(m):
                if (matrix[i][j] == 0):
                    rows[i] = 1
                    col[j] = 1
        
        for i in range(n):
            for j in range(m):
                if (rows[i] == 1 or col[j] == 1):
                    matrix[i][j] = 0

        
        