# {
# Driver Code Starts
# Initial Template for Python 3


# } Driver Code Ends
# User function Template for python3


class Solution:
    def ok(self, a, n, d, k):
        cnt = 0
        for i in range(1, n):
            cnt += (a[i] - a[i - 1]) // d

        return cnt <= k

    def findSmallestMaxDist(self, stations, K):
        # Code here
        lo, hi = 0, stations[-1]
        n = len(stations)
        ans = hi
        eps = 1e-6
        while hi - lo > eps:
            mi = (lo + hi) / 2
            if self.ok(stations, n, mi, K):
                ans = mi
                hi = mi
            else:
                lo = mi

        return ans


# {
# Driver Code Starts.
import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        stations = list(map(int, input().split()))
        K = int(input())
        ob = Solution()
        print("%.2f" % ob.findSmallestMaxDist(stations, K))
# } Driver Code Ends
