class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        m = 0

        for i in range(len(nums)):
            if (nums[i] == target):
                return i

        if (target < nums[0]):
            return 0

        if (target > nums[len(nums) - 1]):
            return len(nums)

        for i in range(len(nums)):
            if (nums[i] > target):
                m = i
                break
                
        return m