# User function Template for python3

from typing import List
import sys

sys.setrecursionlimit(10005)


class Solution:
    def reverse(self, St):
        # code here
        def solve(st):
            if len(st) == 0:
                return []
            res = [st.pop()]
            return res + (solve(st))

        St[:] = solve(St)


# {
# Driver Code Starts

# Initial Template for Python 3


for _ in range(int(input())):
    N = int(input())
    St = list(map(int, input().split()))
    ob = Solution()
    ob.reverse(St)
    print(*St)
# } Driver Code Ends
