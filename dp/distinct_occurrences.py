# Your task is to complete this function
# Finction should return Integer
from functools import lru_cache


class Solution:
    def sequenceCount(self, s, t):
        # Code here
        n = len(s)
        m = len(t)

        @lru_cache(maxsize=None)
        def f(i, j):
            if j == m:
                return 1
            if i == n:
                return 0

            ans = f(i + 1, j)
            if s[i] == t[j]:
                ans += f(i + 1, j + 1)

            return ans % 1000000007

        return f(0, 0)


# {
# Driver Code Starts
# Initial template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        arr = input().strip().split()
        print(Solution().sequenceCount(str(arr[0]), str(arr[1])))
# } Driver Code Ends
