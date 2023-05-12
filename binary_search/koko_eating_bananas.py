# User function Template for python3


class Solution:
    def ok(self, m, n, p, h):
        days = 0
        for i in range(n):
            days += (p[i] + m - 1) // m

        return days <= h

    def Solve(self, N, piles, H):
        # Code here
        lo, hi = 1, int(1e9)
        ans = 0
        while lo <= hi:
            mi = (lo + hi) // 2
            if self.ok(mi, N, piles, H):
                ans = mi
                hi = mi - 1
            else:
                lo = mi + 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        piles = list(map(int, input().split()))
        H = int(input())
        ob = Solution()
        print(ob.Solve(N, piles, H))
# } Driver Code Ends
