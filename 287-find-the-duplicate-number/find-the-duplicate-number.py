class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        slow = 0
        fast = 0

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]

            if slow == fast:
                break

        slow1 = 0
        while True:
            slow1 = nums[slow1]
            slow = nums[slow]

            if slow == slow1:
                break

        return slow