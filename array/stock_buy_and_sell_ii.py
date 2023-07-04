from typing import List


class Solution:
    def stockBuyAndSell(self, n: int, prices: List[int]) -> int:
        # code here
        ans = 0
        prev = prices[0]
        for i in range(1, n):
            if prices[i] > prev:
                ans += prices[i] - prev
            prev = prices[i]

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

        prices = IntArray().Input(n)

        obj = Solution()
        res = obj.stockBuyAndSell(n, prices)

        print(res)


# } Driver Code Ends
