# User function Template for python3
from functools import lru_cache


class Solution:
    def nextHappy(self, N):
        # code here

        @lru_cache(maxsize=None)
        def f(n):
            if n == 1 or n == 7:
                return True
            elif n <= 9:
                return False

            ans = 0
            while n:
                d = n % 10
                ans += d * d
                n //= 10

            return f(ans)

        n = N + 1
        while True:
            if f(n):
                return n
            n += 1
        return -1


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.nextHappy(N))
# } Driver Code Ends
