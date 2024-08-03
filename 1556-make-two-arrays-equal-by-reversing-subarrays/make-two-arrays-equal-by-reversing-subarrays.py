class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """

        if(len(target)!=len(arr)):
            return False


        count_target = {}
        count_arr = {}

        for num in target:
            count_target[num] = count_target.get(num,0) + 1

        for num in arr:
            count_arr[num] = count_arr.get(num,0) + 1

        if (count_target == count_arr):
            return True

        else:
            return False