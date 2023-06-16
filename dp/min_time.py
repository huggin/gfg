from typing import List


class Solution:
    def minTime(self, n: int, locations: List[int], types: List[int]) -> int:
        # code here
        a = {}
        for i in range(n):
            if types[i] not in a:
                a[types[i]] = [locations[i], locations[i]]
            else:
                a[types[i]][0] = min(a[types[i]][0], locations[i])
                a[types[i]][1] = max(a[types[i]][1], locations[i])

        n = len(a)
        dp = [(0, 0)]
        mi_prev, ma_prev = 0, 0
        for idx in sorted(a):
            mi, ma = a[idx]
            left = (
                min(dp[-1][0] + abs(ma - mi_prev), dp[-1][1] + abs(ma - ma_prev))
                + ma
                - mi
            )
            right = (
                min(dp[-1][0] + abs(mi - mi_prev), dp[-1][1] + abs(mi - ma_prev))
                + ma
                - mi
            )
            dp.append((left, right))
            mi_prev, ma_prev = mi, ma

        return min(dp[-1][0] + abs(mi_prev), dp[-1][1] + abs(ma_prev))


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

        locations = IntArray().Input(n)

        types = IntArray().Input(n)

        obj = Solution()
        res = obj.minTime(n, locations, types)

        print(res)


# } Driver Code Ends
