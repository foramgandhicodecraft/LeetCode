class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        rows = len(matrix)
        cols = len(matrix[0])
        count = 0

        left, right = 0, rows*cols-1

        while (left <= right):
            mid = (left + right) // 2

            mid_value = matrix[mid//cols][mid%cols]

            if mid_value == target:
                count += 1
                break

            elif mid_value > target:
                right = mid - 1

            else:
                left = mid + 1

        if count == 1:
            return True
        else:
            return False
