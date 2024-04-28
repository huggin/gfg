from typing import List


class Solution:
    def minimizeDifference(self, n: int, k: int, arr: List[int]) -> int:
        # code here
        premax = [0] * n
        premin = [0] * n
        sufmax = [0] * n
        sufmin = [0] * n
        premax[0] = arr[0]
        premin[0] = arr[0]
        for i in range(1, n):
            premax[i] = max(premax[i - 1], arr[i])
            premin[i] = min(premin[i - 1], arr[i])

        sufmax[n - 1] = arr[n - 1]
        sufmin[n - 1] = arr[n - 1]
        for i in range(n - 2, -1, -1):
            sufmax[i] = max(sufmax[i + 1], arr[i])
            sufmin[i] = min(sufmin[i + 1], arr[i])

        ans = min(premax[n - k - 1] - premin[n - k - 1], sufmax[k] - sufmin[k])
        for i in range(n - k - 1):
            ans = min(
                ans,
                max(premax[i], sufmax[i + k + 1]) - min(premin[i], sufmin[i + k + 1]),
            )
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

        k = int(input())

        arr = IntArray().Input(n)

        obj = Solution()
        res = obj.minimizeDifference(n, k, arr)

        print(res)


# } Driver Code Ends
