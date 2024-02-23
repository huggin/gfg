from typing import List
from functools import lru_cache


class Solution:
    def maxProfit(self, n: int, price: List[int]) -> int:
        # code here
        dp1 = [0] * n
        dp2 = [0] * n
        mi = price[0]
        for i in range(n):
            if price[i] >= mi:
                dp1[i] = max(dp1[i - 1], price[i] - mi)
            else:
                mi = price[i]
                dp1[i] = dp1[i - 1]

        ma = price[n - 1]
        for i in range(n - 2, -1, -1):
            if price[i] <= ma:
                dp2[i] = max(dp2[i + 1], ma - price[i])
            else:
                dp2[i] = dp2[i + 1]
                ma = price[i]

        ans = max(dp1[n - 1], dp2[0])
        for i in range(1, n):
            ans = max(ans, dp1[i - 1] + dp2[i])
        return ans


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

        price = IntArray().Input(n)

        obj = Solution()
        res = obj.maxProfit(n, price)

        print(res)


# } Driver Code Ends
