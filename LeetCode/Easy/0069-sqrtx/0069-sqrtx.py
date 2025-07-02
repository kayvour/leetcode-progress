import math

class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        low, high = 1, x // 2
        ans = 1

        while low <= high:
            mid = (low + high) // 2
            sq = mid * mid

            if sq == x:
                return mid

            elif sq < x:
                ans = mid
                low = mid + 1 

            else:
                high = mid - 1

        return ans
