class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """

        count = 0

        for i in details:
           sub_string = i[11:13]
           age = int(sub_string)

           if (age > 60):
             count = count + 1 

        return count

