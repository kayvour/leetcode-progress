import math

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        
        log2_n = math.log(n,2)
        nearest = round(log2_n)

        return abs(log2_n - nearest) < 1e-10