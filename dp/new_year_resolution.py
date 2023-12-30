from typing import List


class Solution:
    def isPossible(self, N: int, coins: List[int]) -> bool:
        # code here
        dp = [0] * 2025
        dp[0] = 1
        for c in coins:
            for i in range(2024, -1, -1):
                if i + c <= 2024 and dp[i] == 1:
                    dp[i + c] = 1

        if dp[2024] == 1:
            return True
        for i in range(1, 2025):
            if dp[i] == 1 and (i % 20 == 0 or i % 24 == 0):
                return True
        return False


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
        N = int(input())

        coins = IntArray().Input(N)

        obj = Solution()
        res = obj.isPossible(N, coins)

        result_val = 1 if res else 0
        print(result_val)

# } Driver Code Ends
