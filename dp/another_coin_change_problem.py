from typing import List


class Solution:
    def solve(self, t, k, coins, dp):
        if t == 0 and k == 0:
            return 1

        if t < 0 or k < 0:
            return 0

        if dp[k][t] != -1:
            return dp[k][t]

        ans = 0
        for c in coins:
            ans = max(ans, self.solve(t - c, k - 1, coins, dp))
            if ans == 1:
                dp[k][t] = 1
                return ans

        dp[k][t] = 0
        return 0

    def makeChanges(self, N: int, K: int, target: int, coins: List[int]) -> bool:
        # code here
        dp = [[-1 for _ in range(target + 1)] for _ in range(K + 1)]
        return self.solve(target, K, coins, dp)


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

        K = int(input())

        target = int(input())

        coins = IntArray().Input(N)

        obj = Solution()
        res = obj.makeChanges(N, K, target, coins)

        result_val = 1 if res else 0
        print(result_val)

# } Driver Code Ends
