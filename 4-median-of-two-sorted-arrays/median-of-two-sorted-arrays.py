class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        merged_array = nums1 + nums2
        merged_array.sort()

        length = len(merged_array)

        if (length % 2 == 0):
            l = length//2
            ans = (merged_array[l-1] + merged_array[l]) / 2.0
            return ans

        else:
            l = length//2
            ans = merged_array[l]
            return ans
        