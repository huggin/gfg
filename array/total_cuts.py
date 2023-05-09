from typing import List


class Solution:
    def totalCuts(self, N: int, K: int, A: List[int]) -> int:
        # code here
        largest = [0] * N
        smallest = [0] * N

        largest[0] = A[0]
        for i in range(1, N):
            largest[i] = max(largest[i - 1], A[i])

        smallest[N - 1] = A[N - 1]
        for i in range(N - 2, -1, -1):
            smallest[i] = min(smallest[i + 1], A[i])

        ans = 0
        for i in range(0, N - 1):
            if largest[i] + smallest[i + 1] >= K:
                ans += 1

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
        N = int(input())

        K = int(input())

        A = IntArray().Input(N)

        obj = Solution()
        res = obj.totalCuts(N, K, A)

        print(res)


# } Driver Code Ends
