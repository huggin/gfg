# {
# Driver Code Starts
# Initial Template for Python 3


class Solution:
    def ok(self, m, k, v, b):
        curr = 0
        for a in b:
            if v >= a:
                curr += 1
                if curr == k:
                    m -= 1
                    curr = 0
            else:
                curr = 0

        return m <= 0

    def solve(self, M, K, bloomDay):
        # Code here
        if M * K > len(bloomDay):
            return -1

        lo, hi = min(bloomDay), max(bloomDay)
        ans = -1
        while lo <= hi:
            mi = (lo + hi) // 2
            if self.ok(M, K, mi, bloomDay):
                ans = mi
                hi = mi - 1
            else:
                lo = mi + 1

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        M, K = list(map(int, input().split()))
        bloomDay = list(map(int, input().split()))
        ob = Solution()
        res = ob.solve(M, K, bloomDay)
        print(res)
# } Driver Code Ends
