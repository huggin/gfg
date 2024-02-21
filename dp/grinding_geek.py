from functools import lru_cache
from typing import List
import math
import sys

sys.setrecursionlimit(10**6)


class Solution:
    def max_courses(self, n: int, total: int, cost: List[int]) -> int:
        # code here
        @lru_cache(maxsize=None)
        def f(i, t):
            if t == 0 or i == n:
                return 0
            if t < cost[i]:
                return f(i + 1, t)

            c = cost[i]
            return max(f(i + 1, t), 1 + f(i + 1, t - c + math.floor(c * 0.9)))

        return f(0, total)


# {
# Driver Code Starts


class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        total = int(input())

        cost = IntArray().Input(n)

        obj = Solution()
        res = obj.max_courses(n, total, cost)

        print(res)


# } Driver Code Ends
