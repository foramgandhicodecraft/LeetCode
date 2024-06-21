class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        unique_nums = []

        for num in nums:
            if num not in unique_nums:
                unique_nums.append(num)

            else:
                unique_nums.remove(num)

        return unique_nums[0]