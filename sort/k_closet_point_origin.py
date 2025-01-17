# User function Template for python3
"""
points : 2-d array containing the (x, y) point
K : number of closest points that we need to fin
return 2d ARRAY containing the k points in increasing order of distance from origi
"""


class Solution:
    def kClosest(self, points, k):
        a = []
        for x, y in points:
            a.append((x * x + y * y, x, y))

        a.sort()
        return [[a[i][1], a[i][2]] for i in range(k)]


# {
# Driver Code Starts
# Initial Template for Python 3

# contributed by RavinderSinghPB
if __name__ == "__main__":
    from collections import defaultdict
    from math import sqrt

    t = int(input())

    for tcs in range(t):
        n, k = [int(x) for x in input().split()]
        arr = [int(x) for x in input().split()]

        arr2d = []
        for i in range(0, 2 * n - 1, 2):
            arr2d.append([arr[i], arr[i + 1]])

        ans = Solution().kClosest(arr2d, k)

        for e in ans:
            print(e[0], e[1], end=" ")
        print()
        print("~")
# } Driver Code End
