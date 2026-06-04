class Solution:
    def climbStairs(self, n: int) -> int:
        if n ==1 or n==0:
            return n
        prev = 1
        prevprev = 1
        # prevprev prev curr 
        for i in range(2, n+1):
            curr = prev + prevprev
            prevprev = prev
            prev = curr 
        return prev
