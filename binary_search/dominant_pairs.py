from typing import List
import bisect


class Solution:
    def dominantPairs(self, n: int, arr: List[int]) -> int:
        # code here
        half = n // 2
        first = arr[:half]
        second = sorted(arr[half:])
        ans = 0
        for a in first:
            target = a // 5
            ans += bisect.bisect(second, target)
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

        arr = IntArray().Input(n)

        obj = Solution()
        res = obj.dominantPairs(n, arr)

        print(res)


# } Driver Code Ends
