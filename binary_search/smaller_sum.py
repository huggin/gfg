from typing import List
import bisect


class Solution:
    def smallerSum(self, n: int, arr: List[int]) -> List[int]:
        # code here
        d = []
        for i in range(n):
            d.append((arr[i], i))

        d.sort()
        prefix = []
        total = 0
        for i in range(n):
            prefix.append(total)
            total += d[i][0]

        ans = [0] * n
        for i in range(n):
            idx = bisect.bisect_left(d, d[i][0], key=lambda x: x[0])
            # idx = bisect.bisect_left(d, (d[i][0], 0))
            ans[d[i][1]] = prefix[idx]

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
        res = obj.smallerSum(n, arr)

        IntArray().Print(res)


# } Driver Code Ends
