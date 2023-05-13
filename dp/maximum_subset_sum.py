from typing import List


class Solution:
    def findMaxSubsetSum(self, N: int, A: List[int]) -> int:
        # code here
        dp = [0] * N
        dp[0], dp[1] = A[0], max(A[1], A[1] + A[0])
        for i in range(2, N):
            dp[i] = max(dp[i - 1], dp[i - 2]) + A[i]
        return max(dp[-1], dp[-2])


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

        A = IntArray().Input(N)

        obj = Solution()
        res = obj.findMaxSubsetSum(N, A)

        print(res)


# } Driver Code Ends
